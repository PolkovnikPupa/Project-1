#include <stdio.h>
#include <limits.h>
#include <stdbool.h>


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

float calculate_P(float A, float B, float C)
{
 float P, t1, t2;
 t1=A*B+C*C;
 t2=B*C+A;
 P = t1/t2;
 return P;
 }
int lr1_dop(void)
{
 float P, A, B, C;
 printf("A=");
 scanf("%f", &A);
 printf("B=");
 scanf("%f", &B);
 printf("C=");
 scanf("%f", &C);

printf("P=%f", calculate_P(A, B, C) );
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

int lr2_dop(void)
{
 long double s,a;
 int n,i,k,x, x1, fak, cnt;
 printf("n=");
 scanf("%d", &n);
 printf("x=");
 scanf("%d", &x);
 s=0;
 k=1;
 i=0;
 x1 = 1;
 fak = 1;
 for(int cnt =0; cnt<n; cnt++)
 {
 a=(x1)/(float)fak;
 s=s+a*k;
 k=-k;
 i=i+2;
 fak = fak*(i-1)*i;
 x1 = x1 * x * x;
 }
 printf("s=%lf",s);
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


#define bool int
#define true 1
#define false 0

bool is_vowel(char c)
{
    if(c == 'a' 
        || c == 'y'
        || c == 'u'
        || c == 'e'
        || c == 'o')
        return true;

    return false;
}


int lr3_dop(void)
{
    int sum = 0;
    int cnt = 0;
    int prevC = 0;
    int c;
    bool is_only_consonants = true;

    prevC = getchar();
    while ((c = getchar()) != '?')
    {
        if (c == ' ' || c == '\n' || c == '\t' || c == ',')
        {
            if (sum == 0 && is_only_consonants == false)
                cnt += 1;
            else
                sum = 0;

            is_only_consonants = true;
            prevC = getchar();
            if (prevC == '?')
                break;

            continue;

        }
        else
        {
            sum += c - prevC;

            if(is_vowel(c) == true)
                is_only_consonants = false;
        }

        prevC = c;
    }

    printf("%d", cnt);


    return 0;
}




void removeDuplicates(char *input_str) {
    int wordCount = 0;
    int wordStart = 0;
    bool foundDuplicate = false;

    for (int i = 0; input_str[i] != '\0'; i++) {
        if (input_str[i] == ' ' || input_str[i] == '\n') {
            foundDuplicate = false;
            for (int j = wordStart; j < i; j++) {
                for (int k = i + 1; k < strlen(input_str); k++) {
                    if (input_str[j] == input_str[k]) {
                        foundDuplicate = true;
                        break;
                    }
                }
            }
            if (!foundDuplicate) {
                for (int j = wordStart; j < i; j++) {
                    printf("%c", input_str[j]);
                }
                if (wordCount > 0) {
                    printf(" ");
                }
                wordCount++;
            }
            wordStart = i + 1;
        }
    }
}

int lr4(void) {
    char input_str[100];

    printf("Введите слова: ");
    fgets(input_str, sizeof(input_str), stdin);

    printf("Результат: ");
    removeDuplicates(input_str);

    return 0;
}



int lr4_dop(void) {
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
struct name {
 int max;
 int sum;
 int cnt;
 float avg;
};
int summ(int arr[10])
{
 int sum = 0;
 for (int i = 0; i < 10; i++)

{
 int num = arr[i];
 while (num > 0)

{
 sum += num % 10;
 num /= 10;

}

}
 return sum; }
int maximum(int arr[10]) {
 int max_num =
-1;
 for (int i = 0; i < 10; i++)

{
 int num = arr[i];
 if (num > max_num)

{
 max_num = num;

}

}
 return max_num; }
int cnt(int arr[10]) {
 int totalDigits = 0;
 for (int i = 0; i < 10; i++) {
 int num = arr[i];
 while (num > 0)

{
 num /= 10;
 totalDigits++;

}

}
 return totalDigits; }
float avg(int arr[10]) {
 int sum = 0;
 int totalDigits = 0;
 for (int i = 0; i < 10; i++) {
 int num = arr[i];
 while (num > 0)
 {
 sum += num % 10;
 num /= 10;
 totalDigits++;
 }
 }
 float average = (float)sum / totalDigits;
 return average;
}
int lr5_dop(void)
{
 int arr[10] = { 123, 456, 789, 321, 654, 987, 741, 852, 963, 159 };
 struct name huina;
 huina.avg = avg(arr);
 huina.sum = summ(arr);
 huina.max = maximum(arr);
 huina.cnt = cnt(arr);
 printf("Сумма цифр: %d\n", huina.sum);
 printf("Общее количество цифр: %d\n", huina.cnt);
 printf("Среднее арифметическое цифр: %.2f\n", huina.avg);
 printf("%d\n", huina.max);
;
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





// Функция для вывода числа в двоичной системе
void printBinary(long long num)
{
    if (num > 1)
        printBinary(num >> 1);

    printf("%lld", num & 1);
}

int lr7(void)
{
    long long n;
    printf("Введите целое число N: ");
    scanf("%lld", &n);

 // Определяем позицию старшей единицы, чтобы обнулить все биты после нее
    int pos = 0;
    long long temp = n;
    while (temp > 0) 
    {
        temp >>= 1;
        pos++;
    }

    // Обнуляем разряды, стоящие правее старшей единицы
    long long mask = 1;
    mask = (mask << (pos - 1)); // Создаем маску из единиц справа от старшей единицы
    long long result = N & mask;

    printf("Исходное число: ");
    printBinary(n);
    printf("\n");

    printf("Позиция старшей единицы: %d\n", pos); // Нумерация битов с 0

    printf("Результат: ");
    printBinary(result);
    printf("\n");

    return 0;
}

