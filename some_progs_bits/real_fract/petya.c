#include <stdio.h>
#include <stdlib.h>

long long int power(int osn, int p);

int main() {

int fl_part = 0, int_part = 0, fl_c = 0;
char c = getchar();
while (c != '.' && c != EOF && c != '\n') {
int_part = int_part * 10 + (c - '0');
c = getchar();
}
while (c != EOF && c != '\n') {
c = getchar();
if (c != EOF && c != '\n') {
fl_part = fl_part * 10 + (c - '0');
fl_c++;
}
}
long long int del = power(10, fl_c);
for (int i = 0; i < fl_c; i++) {
if (fl_part % 2 == 0 && del % 2 == 0) {
fl_part /= 2;
del /= 2;
}
if (fl_part % 5 == 0 && del % 5 == 0) {
fl_part /= 5;
del /= 5;
}
}
printf("%d (%d/%lld)\n", int_part, fl_part, del);
return 0;

}

long long int power(int osn, int p) {
long long int s = 1;
for (int i = 0; i < p; i++)
s *= osn;
return s;
}