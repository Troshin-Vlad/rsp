#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Author Tr.Vlad

#define CLR_RED "\033[31m"
#define CLR_DEF "\033[0m"

void error(char *str);

int main(){

	srand(time(NULL));

	int user;
	int sys = (rand() % 3) + 1;		//Machine step
	char *rsp_array[4] = {"","rock","scissors","paper"};
	char *input_result[2] = {"You Win !(Вы выйграли)","System Win !(Система Выйграла)"};
	char *result;


	printf("-----------------------------------------\n");
	printf("| 1 - Rock(Камень)\t\t\t|\n");
	printf("| 2 - Scissors(Ножницы)\t\t\t|\n");
	printf("| 3 - Paper(Бумага)\t\t\t|\n");
	printf("-----------------------------------------\n");

	/*
		User input
	*/
	printf("Your Step: ");
	scanf("%i",&user);

	//Checking enter answer
	if(user < 1 || user > 3){
		error("no correct value");
	}
	putchar('\n');

	//Enter status, user step and machine step
	printf("Your Step: %s\n",rsp_array[user]);
	printf("System Step: %s\n",rsp_array[sys]);

	putchar('\n');

	/* DRAW/Ничья */
	if(user == sys)
		result = "DRAW(Ничья) !";
	else if(user == 1)
		if(sys == 2)
			result = input_result[0];
		else
			result = input_result[1];
	/* Пользователь ввёл ножницы */
	else if(user == 2)
		if(sys == 1)
			result = input_result[1];
		else
			result = input_result[0];
	/* Пользователь ввёл бумага */
	else if(user == 3)
		if(sys == 1)
			result = input_result[0];
		else
			result = input_result[1];
	/* Неизвестноя ошибка */
	else
		printf("\x1b[1;31mError: Unknow error\x1b[0m\n");

	printf("%s\n",result);
	
	return 0;

}

void error(char *str){
	printf("[%serror%s]: %s\n",CLR_RED,CLR_DEF,str);
	exit(1);
}