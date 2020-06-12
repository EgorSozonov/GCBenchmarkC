#include <stdio.h>
#include <stdlib.h>


const HEIGHT = 2;
#define SIZE_REGION 200000;

struct Tree {
    struct Tree* left;
    struct Tree* right;
		int vals[4];
};


int main(int argc, char** argv) {
    int numRegions = HEIGHT/SIZE_REGION + 1;
		printf("numRegions = %d", numRegions);
		struct Tree** regions = (struct Tree**)malloc(numRegions * sizeof(Tree*));


		return 0;
}

