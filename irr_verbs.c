
void program_meaning()
{
    printf("\nThis program is for checking the");
    printf(" knowledge of irregular verbs\n");
}

//"скелет" программы
int irrverbs(IrrVerb *correct)
{
FILE *a = fopen("IV.txt","r");
if(a==NULL) {
printf("Cannot open file IV.txt\n");
return -1;
}
float score=0;//кол-во правильных ответов
int point;//1 если ответ правильный, 0 в ином случае
int mas[200];//массив случайных неповторяющихся чисел
int k;//случайное число
make_arr(mas, 200);
shuffle(mas, 200);
for(int i = 0 ; i < 40; i++)
{
IrrVerb asd;
correct = &asd;
point=0;
char str1[15],str2[15];
k = mas[i];//случайное число
read_verb(correct,a,k);
printf("%s: ",correct->verb[0]);
scanf("%s%s", str1, str2);
point=check_answer(correct, str1, str2);
score += point;
printf(" Your score is %.0f of 40\n", score);
if(point==0)
{
printf("The right forms of this verb are: ");
printf("%s %s ",correct->verb[0],correct->verb[1]);
printf("%s\n",correct->verb[2]);
}
}
float result;
result = (score / 10) * 100;
printf("Percentage of correct answers: %.0f%%\n",result);
return 0;
}
