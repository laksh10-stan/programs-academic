#include <stdio.h>
#include <conio.h>
main()
{
	int a;
	printf ("Enter the no:\n");
	scanf ("%d",&a);
	switch (a)
	{
		case 1:
			printf ("Monday");
			break;
			case 2:
				printf ("Tuesday");
				break;
				case 3:
				printf ("Wednesday");
				break;
				case 4:
					printf ("Thursday");
					break;
					case 5:
						printf ("Friday");
						break;
						case 6:
							printf ("Saturday");
							case 7:
								printf ("Sunday");
								break;
								default:
									printf ("Wrong Input");
	}
}
