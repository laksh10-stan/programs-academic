#include <vector>
#include <algorithm>
#include <iostream>
#include <array>
#include <numeric>
#include <cassert>
#include <bits/stdc++.h>

namespace details
{
    const int kNoDigit = -1;
    int ExtractDigit(int i, int pos) {
        const int digitsCount = log10(i) + 1;
        if (pos > digitsCount) return kNoDigit;
        return (int)(i / pow(10, digitsCount - pos)) % 10;
    }

    // For pos equals to 2 and {10 20 1} -> {0, 1, 3, 3, ...},
    // 1 ends with empty digit in the second digit and 2 ends with 0
    template <class It>
    auto CountingSort(It begin, It end, int pos) {
        std::array<int, 12> bins;
        std::fill(bins.begin(), bins.end(), 0);
        for (auto it = begin; it < end; ++it) {
            const int digit = ExtractDigit(*it, pos);
            ++bins[digit + 1];
        }
        std::partial_sum(bins.cbegin(), bins.cend(), bins.begin());
        std::move(bins.cbegin(), bins.cend() - 1, bins.begin() + 1);
        return bins;
    }

    template <class It>
    void MsdRadixInternal(It begin, It end, int pos) {
        const auto bins = CountingSort(begin, end, pos);
        // We finish when i is 1, because the last part ends up sorted anyway
        for (int i = 10; i > 0; --i) {
            const int digit = i - 1;
            const auto local_begin = begin + bins[i];
            const auto local_end = begin + bins[i + 1];
            if (local_begin == begin) break;
            if (std::distance(local_begin, local_end) > 0) {
                auto crsrForward = begin;
                auto crsrBackward = local_end - 1;
                while (crsrForward < crsrBackward) {
                    assert(crsrForward < local_begin && local_begin <= crsrBackward);
                    while (ExtractDigit(*crsrBackward, pos) == digit) --crsrBackward;
                    while (ExtractDigit(*crsrForward, pos) != digit) ++crsrForward;
                    if (crsrForward < local_begin) {
                        std::swap(*crsrBackward, *crsrForward);
                    }
                    ++crsrForward;
                }
            }
        }
        // Start from 1 as we don't want to sort numbers wich are out of digits in pos already
        for (int i = 1; i < 11; ++i) {
            if (bins[i + 1] - bins[i] > 1)
                MsdRadixInternal(begin + bins[i], begin + bins[i + 1], pos + 1);
        }
    }
}

template <class It>
void MsdRadix(It begin, It end) {
    details::MsdRadixInternal(begin, end, 1);
}

int main()
{
    std::vector<int> v = { 1001,3033, 3032, 1254, 6003, 1165, 5000, 1011, 1213 };
    MsdRadix(v.begin(), v.end());
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    return 0;
}
