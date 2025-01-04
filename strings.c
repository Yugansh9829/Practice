#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct class{
    char *word;
    int freq;
}class;


class *arr[100];

int is_exists(char *word, int counter){
    for(int i=0;i<counter;i++){
        if(strcmp(arr[i]->word, word)==0) return i;
    }
    return -1;
}


void remove_duplicate_word(char *str, int size){
    char *sp = str;
    char *ep = str;
    char *pointer_to_end = str+(size-1);//pointer to last word;
    int counter = 0;
    while(ep <= pointer_to_end){
        while(*(ep)== ' ' && ep<=pointer_to_end)ep++;

        if(ep>pointer_to_end) break;

        sp = ep;

        while(*(ep)!=' ' && *ep!='\0')ep++;

        //if ep is at last \0 then?
        *ep = '\0';
        char * word = sp;

        int index = is_exists(word, counter);

        if(index==-1){
            class *obj = (class *)malloc(sizeof(obj));
            obj->word = (char *)malloc(100*sizeof(word));

            obj->word = word;
            obj->freq = 1;
            arr[counter++] = obj;
        }else{
            arr[index]->freq +=1;
        }

        ep++;        
    }

    for(int i=0;i<counter;i++){
        printf("%s ", arr[i]->word);
    }

    // //to printf word in new string which are having frequency greater than 1;
    // char *ptr = (char *)malloc(100*sizeof(ptr));
    // char *f_ptr = ptr;
    // for(int i=0;i<counter;i++){
    //     if(arr[i]->freq>1){
    //         char *p = arr[i]->word;

    //         while(*(p)!='\0') *ptr++ = *p++;
    //        *ptr++ = ' ';
    //     }
    // }
    // *ptr='\0';
    // printf("%s", f_ptr);


}

void copy_string(char *str){
    char *dest = (char *)malloc(100*(sizeof(char)));
    char *ptr = dest;
    while(*(str)!='\0'){
        *dest++ = *str++;
    }
    printf("%s", ptr);
}

void to_lower(char *ptr){
    *ptr += 32;
}

void to_upper(char *ptr){
    *ptr -= 32;
}



void reverse_case(char *str, int size){
    char *ptr=str;
    while(*(ptr)!='\0'){
        if(*ptr>=97 && *ptr<=122) to_upper(ptr);
        else if(*ptr>=65 && *ptr<=90) to_lower(ptr);
        ptr++;
    }
    printf("%s", str);
}

void is_rotation(char *str1, char*str2, int size){
    str2+=(size-1);
    while(*str1!='\0'){
        if(*str1++ != *str2--){
            printf("both strings are not rotation of each others.");
            return;
        }
    }
    printf("both strings are rotation of each others.");
    return ;
}

int is_palindromic(char str[], int start, int end){
    while(start<end){
        if(str[start++]!=str[end--]) return 0;
    }
    return 1;
}

void longest_palindromic_substring(char str[], int size){
    char ans[100] = "";
    int len = 0;
    int start = -1;
    int end = -1;
    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            if((j-i)>len && is_palindromic(str, i, j)){
                len = (j-i);
                start = i; end = j;
            }
        }
    }
    int i=0;
    for(int itr = start;itr<=end;itr++){
        ans[i++] = str[itr];
    }

    printf("%s\n", ans);

}

void longest_common_substring(char str1[], char str2[], int i, int j, int len, int *ans){

    if(len>*(ans)) *(ans) = len;

    if(i==strlen(str1) || j==strlen(str2)) return;

    if(str1[i]==str2[j]){
        longest_common_substring(str1, str2, i+1, j+1, len+1, ans);
        return;
    }
    longest_common_substring(str1, str2, i+1, j, 0, ans);
    longest_common_substring(str1, str2, i, j+1, 0, ans);

    return;
}

int longest_common_subsequence(char str1[], char str2[], int i, int j){
    if(i==strlen(str1) || j==strlen(str2)) return 0;

    if(str1[i]==str2[j]) return 1 + longest_common_subsequence(str1, str2, i+1, j+1);

    int a = longest_common_subsequence(str1, str2, i+1, j);
    int b = longest_common_subsequence(str1, str2, i, j+1);

    if(a>b) return a;
    return b;
}

void remove_all_occurances_of_substring(char str[], char substr[]){
    // char arr[100];

    // int size = strlen(substr);
    // int end = strlen(str);

    // for(int i=0;i<size-1;i++){
    //     arr[i]= str[i];
    // }
    // for(int i=(size-1);i<end;i++){
    //     // arr[i] = str[i];
    //     if(arr[i] = str[i]){
    //         int flag = 0;
    //         for(int j=0;j<size;j++) if(arr[i-j]!=str[])
    //     }
    // }

    

}


void swap(int arr[], int *ptr, int *i){
    int temp = *ptr;
    *i = *ptr;
    *ptr = temp;
    return;
}


int main(){
    // char *str = (char *)malloc(100*sizeof(char));
    // char *str2 = (char *)malloc(100*sizeof(char));

    // scanf("%[^\n]s", str);
    // fflush(stdin);
    // scanf("%[^\n]s", str2);
    // char str1[100];
    // scanf("%[^\n]s", &str1);
    // fflush(stdin);
    // char str2[100];
    // scanf("%[^\n]s", &str2);

    int arr[] = {0, 0, 0, 2, 2, 2, 1, 1, 1, 0};

    int *pointer_to_0 = arr;
    int size = sizeof(arr)/sizeof(int);
    int *pointer_to_2 = arr+(size-1);

    int *ptr = arr;
    while(ptr<(arr+size)){
        if(*ptr==0) swap(arr, pointer_to_0++, ptr);
        
        if(*ptr==2){
            swap(arr, pointer_to_2--, ptr);
            if(*ptr==0)continue;
        }

        ptr++;
    }

    for(int i=0;i<size;i++){
        printf("%d ", arr[i]);
    }

    // int size = strlen(str);
    // int ans = 0;
    // longest_palindromic_substring(str, size);
    // longest_common_substring(str1, str2, 0 , 0, 0, &ans);

    // remove_all_occurances_of_substring(str2,str2);
    // printf("%d",ans);

    // is_rotation(str, str2, size);
    // copy_string(str);

    // remove_duplicate_word(str, size);
    // reverse_case(str, size);

    // free(str);free(str2);

    return 0;
}