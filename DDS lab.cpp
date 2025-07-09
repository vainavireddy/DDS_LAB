#include<stdio.h>
#include<ctype.h>//isalnum
#include<string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;
 
void push(char ch){
	stack[++top] = ch;
}

char pop(){
	if(top==-1)return -1;
	return stack[top--];
}
char peek(){
	if(top==-1)return -1;
	return stack[top];
}

int precedence(char ch){
	
	if(ch=='^')return 3;
	if(ch=='*'||ch=='/')return 2;
	if(ch=='+'||ch=='-')return 1;
	return 0;
}

void infixToPostfix(char infix[],char postfix[]){
	int i,j=0;
	char c;
	for(i=0;i<strlen(infix);i++){
		c=infix[i];
		if(isalnum(c)){
			postfix[j++]=c;
		}
		else if(c=='('){
			push(c);
		}
		else if(c==')'){
			while(peek()!='('&& top !=-1){
				postfix[j++]=pop();
			}
			pop();
		}
		else{
			while(precedence(peek())>=precedence(c)){
				postfix[j++]=pop();
			}
			push(c);
		}
	}
}
while(top!=-1){
	postfix[j++]=pop();
}
  postfix[j]='\0';
}
 int main(){
 char infix[SIZE],postfix[SIZE];
 printf("enter infix expression:");
 scanf("%s",infix);
 
 infixToPostfix(infix,postfix);
 
 printf("postfix expression:%s\n",postfix);
 
 return 0;
 }
 
