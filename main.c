#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
bool input(long*nump)
{
	char s[100];
	bool valid = false;
	if(fgets(s, sizeof(s), stdin) ==  NULL)
		exit(0);
	size_t len = strlen(s);
	if(len > 10) {
		printf("too big value entered");
		exit(-1);
	}
	while (len > 0 && isspace(s[len - 1]))
	    len--;     // strip trailing newline or other white space
	if (len > 0)
	{
	    valid = true;
	    for (int i = 0; i < len; ++i)
	    {
	        if (!isdigit(s[i]))
	        {
	            valid = false;
	            break;
	        }
	    }
	}
	sscanf(s, "%d", nump);
	return valid;
}
int main(void)
{
	bool perfect(long x) 
	{
		if(x <= 0)
			return false;
		//printf("y=%d\n", x);
		return ((long)(sqrt(x))*(long)(sqrt(x)) == x);
	}
	while(1) {
		printf("input n:");
		long n;
		char buf[100];
		n=0;

		bool res = input(&n);
		if(n<=0 || n > LONG_MAX || !res) {
			printf("value <%d> incorrect or out of bounds\n", n);
			return -1;
		}
		long a,b;
		// verify spec cases
		if(n%2 == 0 ) {
			a=2;
			b=n/2;
		} else {
			long x=(long)ceil(sqrt(n));
			while(!perfect(x*x-n)) {
				//printf("x=%d y=%d\n", x, x*x-n);
				x++;
			}
			long y = (long)sqrt(x*x-n);
			a = x - y;
			b = x + y;
		}
		printf("a=%ld, b=%ld\n", a,b);
	}
	return 0;
}
