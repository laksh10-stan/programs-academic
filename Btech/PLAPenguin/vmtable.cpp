#include<iostream>
class B
{
	public:
		virtual void bar();
		virtual void qux();
		
};
void B::bar()
{
	std::cout << "This is B's implementation of bar " << std::endl;
}
void B::qux()
{
	std::cout << "This is B's implementation of qux " << std::endl;

}
class C : public B
{
	public:
		void bar() override;
		
};
void C::bar()
{
	std::cout << "This is C's implementation of bar " << std::endl;
}
int main()
{
	B* b = new C();
	b->bar();
}
