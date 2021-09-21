#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
    int coeff;
    int exp;
    struct Node *next;
} *polyNode = NULL;

void createNodes() {
    struct Node *tempNode, *lastNode = NULL;
    int num, i;

    printf("Enter number of terms: ");
    scanf("%d", &num);
    printf("Enter each term with coeff and exp\n");

    for (int i = 0; i < num; i++) {
        tempNode = (struct Node *) malloc(sizeof(struct Node));
        scanf("%d%d", &tempNode->coeff, &tempNode->exp);
        tempNode->next = NULL;
        if (polyNode == NULL) {
            polyNode = lastNode = tempNode;
        } else {
            lastNode->next = tempNode;
            lastNode = tempNode;
        }
    }
}

void Display(struct Node *pointNode) {
    while (pointNode) {
        printf("%dx%d +", pointNode->coeff, pointNode->exp);
        pointNode = pointNode->next;
    }

    printf("\n");
}

long Eval(struct Node *pointNode, int x) {
    long value = 0;

    while (pointNode) {
        value += pointNode->coeff * pow(x, pointNode->exp);
        pointNode = pointNode->next;
    }

    return value;
}

int main() {
    createNodes();
    Display(polyNode);
    printf("%ld\n", Eval(polyNode, 1));

    return 0;
}