#include <stdio.h>

enum calculator {
    cal1 = 0,     // +
    cal2,    // -
    cal3,      // *
    cal4,     // /
    cal5,      // &
    cal6,     // |
    cal7,    // !
};




int main() {
    int input1, input2;
    int opr;
    printf("enter number1");
    scanf("%d", &input1);
    printf("enter number2");
    scanf("%d", &input2);
    getchar();
    
    printf("Enter operation (0 = +, 1 = -,2 = *, 3 = /, 4 = &, 5 = |,6 = !): ");
    scanf("%d", &opr);
    if (opr == 0)
    {
        printf("%d", input1 + input2);
        
    }else if(opr == 1){
        printf("%d", input1 - input2); 
    }else if(opr == 2){
        printf("%d", input1 * input2);
    }else if(opr == 3){
        printf("%d", input1 / input2); 
    }
     


    
    return 0;
}
