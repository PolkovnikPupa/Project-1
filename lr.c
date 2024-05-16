#include <string.h>
#include <stdio.h>

int lr1(void)
{
  float P, A, B, C, t1, t2;
  printf("A=");
  scanf("%f", &A);
  printf("B=");
  scanf("%f", &B);
  printf("C=");
  scanf("%f", &C);
  t1=A*B+C*C;
  t2=B*C+A;
  if(t2==0)
  {
    printf("деление на ноль\n");
    return -1;
  }

  P=t1/t2;
  printf("P=%f", P);

  return 0;
}

int lr2(void)
{
    float s,a;
    int n,i,k,x, x1, fuck, cnt;
    printf("n=");
    scanf("%d", &n);
    printf("x=");
    scanf("%d", &x);
    s=0;
    k=1;
    i=0;
    cnt = 0;
    x1 = 1;
    fuck = 1;
    while(cnt<n)
    {
        a=(x1)/(float)fuck;
        s=s+a*k;
        k=-k;
        i=i+2;
        fuck = fuck*(i-1)*i;
        x1 = x1 * x * x;
        cnt += 1;
    }
    printf("s=%f",s);

    return 0;
}




int lr3(void)
{
    int sum = 0;
    int cnt = 0;
    int prevC = 0;
    int c;
    prevC = getchar();
    while ((c = getchar()) != '?')
    {
        if (c == ' ' || c == '\n' || c == '\t' || c == ',')
        {
            if (sum == 0)
                cnt += 1;
            else
                sum = 0;

            prevC = getchar();
            if (prevC == '?')
                break;

            continue;

        }
        else
            sum += c - prevC;


        prevC = c;
    }

    printf("%d", cnt);


    return 0;
}





int lr4(void) {
    char inputprintf[1000];
    printf("Введите символьную строку: ");
    getchar();
    fgets(inputprintf, 1000, stdin);

    char *token;
    char *words[100];
    int wordCount = 0;

    token = strtok(inputprintf, " ");
    words[wordCount++] = token;

    while (token != NULL) {
        token = strtok(NULL, " ");
        if (token != NULL) {
            int repeat = 0;
            for (int i = 0; i < wordCount; i++) {
                if (strcmp(token, words[i]) == 0) {
                    repeat = 1;
                    break;
                }
            }

            if (!repeat) {
                words[wordCount++] = token;
            }
        }
    }

    for (int i = 0; i < wordCount; i++) {
        char filteredWord[100];
        int k = 0;
        int repeat = 0;
        for (int j = 0; words[i][j] != '\0'; j++) {
            if (words[i][j] != 'a' && words[i][j] != 'e' && words[i][j] != 'i' && words[i][j] != 'o' && words[i][j] != 'u' &&
                words[i][j] != 'A' && words[i][j] != 'E' && words[i][j] != 'I' && words[i][j] != 'O' && words[i][j] != 'U') {
                filteredWord[k++] = words[i][j];
            }
        }
        filteredWord[k] = '\0';

        // Удаление повторяющихся слов
        for (int n = 0; n < i; n++) {
            if (strcmp(filteredWord, words[n]) == 0) {
                repeat = 1;
                break;
            }
        }

        // Если слово не повторяется, выводим его
        if (!repeat) {
            printf("%s ", filteredWord);
        }
    }

    return 0;
}







int lr5(void) {
    int arr[10] = {123, 456, 789, 321, 654, 987, 741, 852, 963, 159};
    int sum = 0;
    int totalDigits = 0;

    for (int i = 0; i < 10; i++) {
        int num = arr[i];
        while (num > 0) {
            sum += num % 10; // Добавляем последнюю цифру числа к сумме
            num /= 10; // Убираем последнюю цифру числа
            totalDigits++; // Увеличиваем счетчик цифр
        }
    }

    float average = (float)sum / totalDigits; // Вычисляем среднее арифметическое

    printf("Сумма цифр: %d\n", sum);
    printf("Общее количество цифр: %d\n", totalDigits);
    printf("Среднее арифметическое цифр: %.2f\n", average);

    return 0;
}



#include <stdio.h>
#define N 5
#define K 3
void sortRowsByAverage(int arr[][K]) {
 float avg[N];
 for (int i = 0; i < N; i++) {
 int sum = 0;
 for (int j = 0; j < K; j++) {
 sum += arr[i][j];
 }
 avg[i] = (float)sum / K;
 }
 for (int i = 0; i < N - 1; i++) {
 for (int j = i + 1; j < N; j++) {
 if (avg[i] < avg[j]) {
 for (int k = 0; k < K; k++) {
 int temp = arr[i][k];
 arr[i][k] = arr[j][k];
 arr[j][k] = temp;
 }
 float temp_avg = avg[i];
 avg[i] = avg[j];
 avg[j] = temp_avg;
 }
 }
 }
}
int lr6(void) 
{
 int arr[][K] = { {3, 6, 9},
 {1, 4, 7},
 {2, 5, 8},
 {10, 20, 30},
 {15, 25, 35} };
 sortRowsByAverage(arr);
 printf("Sorted massive:\n");
 for (int i = 0; i < N; i++) {
 for (int j = 0; j < K; j++) {
 printf("%d ", arr[i][j]);
 }
 printf("\n");
 }
 return 0;
}


#include <stdio.h>
#include <math.h>
int lr7(void)
{
  int n;
  int cnt = 1;
  int index;
  scanf("%d", &n);
  int n1 = n;

  while(n > 0)
  {
     if (n % 10 == 1)
     {
       index = cnt;
       cnt += 1;
       n /=10;
     }
    else
     {
      cnt += 1;
      n /=10;
     }
  } 
n1 = n1 / pow(10, (index - 1));
n1 = n1 * pow(10, (index - 1));
printf("%d", n1);
}
