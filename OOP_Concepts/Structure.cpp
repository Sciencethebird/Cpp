#include <stdio.h>
#include <ctype.h> //�ޤJ�r�����ջP�ഫ��Ƽ��Y��

struct student{
  int id;
  char name[10];
};

void new_student(student new_one){
    new_one.id = 1000 + new_one.id;
    for(int i = 0; new_one.name[i] != '\0'; i++){
      new_one.name[i] = toupper(new_one.name[i]);
    }
    printf("�s�ǥ�id�G%d\n", new_one.id); //��new_one���ȦL�X��
    printf("�s�ǥͩm�W�G%s\n", new_one.name); //��new_one���ȦL�X��
};

int main(void) {
  student john = {291, {'j', 'o', 'h', 'n', '\0'}};
  new_student(john);
  printf("\n");
  printf("�Ǹ��G%d\n", john.id); //��john���ȦL�X��
  printf("�m�W�G%s\n", john.name); //��john���ȦL�X��
}
