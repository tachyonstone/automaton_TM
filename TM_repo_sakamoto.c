#include <stdio.h>

#define N 11

void print_array(int array[N])
{
  int i;

  printf("...");
  for(i = 0; i < N; i++){
	printf("|%d", array[i]);
  }

  printf("|...\n");

  return;

}

int q_0(int *status, int tape_symbol, int *i)
{
  if(tape_symbol == 0){
	*i = *i+1;
	*status = 0;
	return 0;
  }else{
	*i = *i+1;
	*status = 1;
	return 0;
  }

}

int q_1(int *status, int tape_symbol, int *i)
{
  if(tape_symbol == 0){
	*i = *i+1;
	*status = 2;
	return 0;
  }else{
	*i = *i+1;
	*status = 1;
	return 1;
  }

}

int q_2(int *status, int tape_symbol, int *i)
{
  if(tape_symbol == 0){
	*i = *i-1;
	*status = 3;
	return 1;
  }else{
	*i = *i+1;
	*status = 2;
	return 1;
  }

}

int q_3(int *status, int tape_symbol, int *i)
{
  if(tape_symbol == 0){
	*i = *i-1;
	*status = 4;
	return 0;
  }else{
	*i = *i-1;
	*status = 3;
	return 1;
  }

}

int q_4(int *status, int tape_symbol, int *i)
{
  if(tape_symbol == 0){
	*i = *i+1;
	*status = 6;
	return 0;
  }else{
	*i = *i-1;
	*status = 5;
	return 1;
  }

}

int q_5(int *status, int tape_symbol, int *i)
{
  if(tape_symbol == 0){
	*i = *i+1;
	*status = 0;
	return 0;
  }else{
	*i = *i-1;
	*status = 5;
	return 1;
  }

}

int q_H(int *status, int tape_symbol, int *i)
{
  if(tape_symbol == 0){
	*i = *i+1;
	*status = 7;
	return 0;
  }else{
	*i = *i+1;
	*status = 7;
	return 0;
  }

}

void state_transition(int *status, int tape[N], int *i)
{
  int j;

  j = *i;

  if(*status == 0){
	tape[j] = q_0(status, tape[j], i);
  }else if(*status == 1){
	tape[j] =q_1(status, tape[j], i);
  }else if(*status == 2){
	tape[j] = q_2(status, tape[j], i);
  }else if(*status == 3){
	tape[j] = q_3(status, tape[j], i);
  }else if(*status == 4){
	tape[j] = q_4(status, tape[j], i);
  }else if(*status == 5){
	tape[j] = q_5(status, tape[j], i);
  }else if(*status == 6){
	tape[j] = q_H(status, tape[j], i);
  }

  return;

}


int main(void)
{
  int i = 0;
  int k = 0;
  int status = 0;
  int tape[N] = {0,0,1,0,1,0,0,0,0};


  while(status != 5){

	state_transition(&status,tape,&i);

	printf("<step%d>\n", k);
	if(status < 5){
	  printf("state:q_%d\n", status);
	}else{
	  printf("state:q_H\n");
	}
	print_array(tape);
	k++;

  }

  return 0;

}
