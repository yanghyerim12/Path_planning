#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define     PI    3.14159
#define     X     0
#define     Y     1
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define     PI    3.14159
#define     X     0
#define     Y     1

float* get_coord_ad(float degree, float distance) {
	float* point = malloc(sizeof(float) * 2);

	degree = PI * degree / 180;
	point[X] = distance * cos(degree);
	point[Y] = distance * sin(degree);

	return point;
}

void print_2d_array(float (*array)[2], int length1, int length2) {
	
	for (int i = 0; i < length1; i++) {
		for (int j = 0; j < length2; j++) {
			printf("%f\t", (*(array + i))[j]);
		}
		printf("\n");
	}
}

int main() {
	float dist, ang, * ptr_coord;
	float angle[5] = { -60,-30,0,30,60 };

	int sample_size = 5;
	int limit = 30;
	int def = limit / sample_size;
	float res[5][2] = { {1,0},{2,0},{3,0},{4,0},{5,0} };


	for (int i = sample_size; i <= limit; i += sample_size) {
		dist = i;
		for (int j = 0; j <= 4; j++) {
			ptr_coord = get_coord_ad(angle[j], dist);
			/*printf("\n±Ø ÁÂÇ¥(%-4.2f, %-4.2f)¸¦ Á÷°¢ ÁÂÇ¥·Î º¯È¯ÇÏ¸é (%-4.2f, %-4.2f)ÀÔ´Ï´Ù.\n",
				dist, angle[j], ptr_coord[X], ptr_coord[Y]);*/
			res[j][0] = ptr_coord[X];
			res[j][1] = ptr_coord[Y];
			free(ptr_coord);
			//printf("%-4.2f, %-4.2f\n", res[j][0], res[j][1]);
	}
		print_2d_array(res,5,2);
		printf("=============\n");

	}
	return 1;
}
