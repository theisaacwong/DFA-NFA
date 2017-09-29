
#include <stdio.h>
#include <stdlib.h>
#include "auto.h"


/*creates a new DFA with n states and returns the dfa */
DFA* DFA_new(int states){
	DFA* dfa = (DFA*)malloc(sizeof(DFA));
	dfa->numStates = states;
	dfa->states = (DFA_state*)malloc(sizeof(DFA_state) * states);

	//printf("# of states for DFA is %d\n", dfa->numStates);

	for(int i = 0; i < states; i++){
		dfa->states[i].isAccepting = -1;
		for(int j = 0; j < 128; j++){
			dfa->states[i].transitions[j] = -1;
		}
	}
	return dfa;
}

/* free the memory used by DFA dfa */
//void DFA_free(DFA* dfa){
//	//	/free(dfa->numStates);
//	free(dfa->states);
//	free(dfa);
//}

/* returns the number of states of the DFA */
int DFA_get_size(DFA* dfa){
	return dfa->numStates;
}

/* args are the dfa, its current state, and the next input
 * returns the next state */
int DFA_get_transition(DFA* dfa, int src, char sym){
	return dfa->states[(int)src].transitions[(int)sym];
}

void DFA_set_transition(DFA* dfa, int src, char str, int dst){
	dfa->states[(int)src].transitions[(int)str] = dst;
	//printf("setting transition: %d, %c, %d\n", src, str, dfa->states[src].transitions[str]);
}

void DFA_set_accepting(DFA* dfa, int state, int value){
	dfa->states[state].isAccepting = value;
}

int DFA_get_accepting(DFA* dfa, int state){
	//printf("accepting?: %d\n", dfa->states[state].isAccepting);
	return dfa->states[state].isAccepting;
}

int DFA_execute(DFA* dfa, char* input){
	//printf("executing\n");

	int src = 0;

	//	int k = 0;
	//	while(input[k] != '\0'){
	//		src = DFA_get_transition(dfa, src , input[k]);
	//		printf("DFA_execute: char: %c   i: %d   GoTo state: %d\n", input[k], k, src);
	//		k++;
	//		if(src == -1){
	//			return -1;
	//		}
	//	}

	for(int i = 0; input[i] != '\0'; i++){



		src = DFA_get_transition(dfa, src , input[i]);
		//printf("DFA_execute: char: %c   i: %d   GoTo state: %d\n", input[i], i, src);
		if(src == -1){
			return -1;
		}
	}

	return DFA_get_accepting(dfa, src);
}

DFA* makePart1a(){
	DFA *ab = DFA_new(3);
	DFA_set_transition(ab, 0, 'a', 1);
	DFA_set_transition(ab, 1, 'b', 2);
	DFA_set_accepting(ab, 2, 1);

	for(int i = 0; i < 3; i++){
		//printf("state: %d accepting: %d   ", i, ab->states[i].isAccepting);
		for(int k = 0; k < 128; k++){
			//printf("%d", ab->states[i].transitions[k]);
		}
		//printf("\n");
	}
	return ab;
}

DFA* makePart1b(){
	DFA *ab = DFA_new(3);
	DFA_set_transition(ab, 0, 'a', 1);
	DFA_set_transition(ab, 1, 'b', 2);
	DFA_set_accepting(ab, 2, 1);

	for(int i = 0; i < 3; i++){
		//printf("state: %d accepting: %d   ", i, ab->states[i].isAccepting);
		for(int k = 0; k < 128; k++){
			//printf("%d", ab->states[i].transitions[k]);
		}
		//printf("\n");
	}
	for(int i = 0; i < 128; i++){
		DFA_set_transition(ab, 2, i, 2);
	}
	return ab;
}

DFA* makePart1c(){
	DFA* dfa = DFA_new(3);

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 128; j++){
			dfa->states[i].transitions[j] = i;
		}
	}
	DFA_set_transition(dfa, 0, '1', 1);
	DFA_set_transition(dfa, 1, '1', 2);
	DFA_set_transition(dfa, 2, '1', 1);
	DFA_set_accepting(dfa, 2, 1);

	return dfa;
}

DFA* makePart1d(){
	DFA* dfa = DFA_new(4);

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 128; j++){
			dfa->states[i].transitions[j] = i;
		}
	}

	DFA_set_transition(dfa, 0, '0', 1);
	DFA_set_transition(dfa, 0, '1', 2);
	DFA_set_transition(dfa, 1, '0', 0);
	DFA_set_transition(dfa, 1, '1', 3);
	DFA_set_transition(dfa, 2, '0', 3);
	DFA_set_transition(dfa, 2, '1', 0);
	DFA_set_transition(dfa, 3, '0', 2);
	DFA_set_transition(dfa, 3, '1', 1);
	DFA_set_accepting(dfa, 0, 1);

	return dfa;
}

//odd number of ones
DFA* makePart1e(){
	DFA* dfa = DFA_new(2);

	//for binary arrays, so it ignores non 1s and 0s
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 128; j++){
			dfa->states[i].transitions[j] = i;
		}
	}

	DFA_set_transition(dfa, 0, '1', 1);
	DFA_set_transition(dfa, 0, '0', 0);
	DFA_set_transition(dfa, 1, '0', 1);
	DFA_set_transition(dfa, 1, '1', 0);

	DFA_set_accepting(dfa, 1, 1);

	return dfa;

}


int ***threeDmalloc(int x, int y, int z){
	int ***p;
	int i, j;
	p = malloc(x * sizeof( *p));
	for (i = 0; i < x; i++){
		p[i] = NULL;
	}
	for (i = 0; i < x; i++){
		p[i] = malloc(y * sizeof( *p[i]));
	}
	for (i=0; i < x; i++){
		for (j=0; j < y; j++){
			p[i][j] = NULL;
		}
	}
	for (i=0; i < x; i++){
		for (j=0; j < y; j++){
			p[i][j] = malloc(z * sizeof( *p[i][j]));
		}
	}
	return p;
}

NFA* NFA_new(int nstates){
	NFA* nfa = (NFA*)malloc(sizeof(NFA));
	nfa->states = threeDmalloc(nstates, 128, nstates);
	//nfa->states = alloc_data(nstates, 128, nstates);
	nfa->acceptingStates = (int*)calloc(nstates, sizeof(int));
	nfa->nstates = nstates;

	for(int i = 0; i < nstates; i++){
		nfa->acceptingStates[i] = -1;
	}
	return nfa;
}



NFA* makePart2c(){

	NFA* n = NFA_new(4);

	int temp[] = {-1, -1, -1, 1};

	n->acceptingStates = temp;
	//n->acceptingStates[3] = 1;

	//first fill everything in with negative one, no state is connected
	for(int i = 0; i < n->nstates; i++){
		for(int j = 0; j < 128; j++){
			for(int k = 0; k < n->nstates; k++){
				n->states[i][j][k] = -1;
			}
		}
	}


	//for state 0, you can only get to state 1 on input 'm'
	n->states[0]['m'][1] = 1;
	//n->states[0]['m'][0] = 1; made repetitive by for loop above
	//for state 1, you can only get to state 2 on input 'a'
	n->states[1]['a'][2] = 1;
	//for state 2, you can only get to state 3 on input 'n'
	n->states[2]['n'][3] = 1;

	for(int i = 0; i < 128; i++){
		for(int k = 0; k < 4; k++){
			n->states[3][i][k] = 1;
		}
	}

	for(int i = 0; i < 4; i++){
		//printf("%d\t", n->acceptingStates[i]);
	}
	//printf("\n");

	return n;

}

NFA* makePart2b(){

	NFA* n = NFA_new(11);

	//            0  1  2  3  4  5  6  7  8  9  10
	//int t[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1};


	int num_letters = 11;


	int* temp = (int*)calloc(num_letters, sizeof(int));
	temp[0] = 1; //start
	temp[1] = 1; //w
	temp[2] = 1; //a
	temp[3] = 1; //s
	temp[4] = 1; //h
	temp[5] = 1; //i
	temp[6] = 1; //n
	temp[7] = 1; //g
	temp[8] = 1; //t
	temp[9] = 1; //o
	temp[10] = -1; //n



	n->acceptingStates = temp;
	//printf("%d", n->nstates);

	//first fill everything in with negative one, no state is connected
	for(int i = 1; i < n->nstates; i++){
		for(int j = 0; j < 128; j++){
			for(int k = 0; k < n->nstates; k++){
				n->states[i][j][k] = -1;
			}
		}
	}

	//next, no matter what state you are at, you can always get to state 0 on any input
	for(int i = 0; i < 128; i++){
		for(int k = 0; k < 11; k++){
			n->states[k][i][0]=1;
		}
	}

	n->states[0][(int)'w'][1] = 1;
	n->states[1][(int)'a'][2] = 1;
	n->states[2][(int)'s'][3] = 1;
	n->states[3][(int)'h'][4] = 1;
	n->states[4][(int)'i'][5] = 1;
	n->states[5][(int)'n'][6] = 1;
	n->states[6][(int)'g'][7] = 1;
	n->states[7][(int)'t'][8] = 1;
	n->states[8][(int)'o'][9] = 1;
	n->states[9][(int)'n'][10] = 1;


	return n;
}


//formerlly makeNFA()
NFA* makePart2a(){
	NFA* n = NFA_new(4);

	int temp[] = {-1, -1, -1, 1};

	n->acceptingStates = temp;
	//n->acceptingStates[3] = 1;

	//first fill everything in with negative one, no state is connected
	for(int i = 0; i < n->nstates; i++){
		for(int j = 0; j < 128; j++){
			for(int k = 0; k < n->nstates; k++){
				n->states[i][j][k] = -1;
			}
		}
	}

	//next, no matter what state you are at, you can always get to state 0 on any input
	for(int i = 0; i < 128; i++){
		for(int k = 0; k < 4; k++){
			n->states[k][i][0]=1;
		}
	}

	//for state 0, you can only get to state 1 on input 'm'
	n->states[0]['m'][1] = 1;
	//n->states[0]['m'][0] = 1; made repetitive by for loop above
	//for state 1, you can only get to state 2 on input 'a'
	n->states[1]['a'][2] = 1;
	//for state 2, you can only get to state 3 on input 'n'
	n->states[2]['n'][3] = 1;

	for(int i = 0; i < 4; i++){
		//printf("%d\t", n->acceptingStates[i]);
	}
	printf("\n");

	return n;

}

int recur(NFA* nfa, int startState, char* input){
	if((nfa->acceptingStates[startState] == 1) && (input[0] == '\0') ){
		return 1;
	}

	if(input[0] == '\0' && nfa->acceptingStates[startState] == -1){
		return -1;
	}

	int temp2 = -1; //does it start at -1????

	for(int i = 0; i < nfa->nstates; i++){
		if(nfa->states[startState][(int)input[0]][i] == 1){
			temp2 = max(temp2, recur(nfa, i, (input + 1) ) );
		}
	}

	return temp2;

}

int max(int i, int k){
	if(i < k){
		return k;
	}
	return i;
}

int execute(NFA* nfa, char* input){
	return recur(nfa, 0, input);
}

//void NFA_free(NFA* nfa){
//
//	for(int i = 0; i < nfa->nstates; i++){
//		for(int j = 0; j < 128; j++){
//			//if(nfa->states[i][j] != NULL)
//			free(nfa->states[i][j]);
//		}
//		//if(nfa->states[i] != NULL)
//		free(nfa->states[i]);
//	}
//	//if(nfa->states != NULL)
//	free(nfa->states);
//	for(int i = 0; i < nfa->nstates; i++){
//		//if(nfa->acceptingStates[i] != NULL)
//		free(nfa->acceptingStates[i]);
//	}
//	//if(nfa->acceptingStates != NULL)
//	free(nfa->acceptingStates);
//
//	//if(nfa->nstates != NULL)
//	free(nfa->nstates);
//
//	free(nfa);
//
//}



DFA* makeIntoDFA(NFA* nfa){

	DFA* dfa = DFA_new(nfa->nstates);

	for(int i = 0; i < dfa->numStates; i++){
		dfa->states[i].isAccepting = nfa->acceptingStates[i];
	}
	for(int i = 0; i < nfa->nstates; i++){
		for(int j = 0; j < 128; j++){
			for(int k = 0; k < nfa->nstates; k++){
				if(nfa->states[i][j][k] == 1){
					DFA_set_transition(dfa, i, j, k);
				}
			}
		}
	}
	return dfa;
}


int main(int argc, char **argv) {
	printf("hello world!\n");

	//	 float f1,f2,f3;
	//
	//	 setbuf(stdout, NULL);
	//
	//	    while (printf("Please enter three numbers.\n") > 0 &&
	//	           prompt_and_read("\tFirst number please.\n", &f1) == 0 &&
	//	           prompt_and_read("\tSecond number please.\n", &f2) == 0 &&
	//	           prompt_and_read("\tThird number please.\n", &f3) == 0)
	//	    {
	//	        printf("Your sum     is %f\n", f1+f2+f3);
	//	        printf("Your average is %f\n", (f1+f2+f3)/3);
	//	    }

	//
	//	char temp[] = {'a', 'b'};
	//
	//	//char* str = &temp;
	//
	//	char str[] = {'a', 'b'};

	int num_letters = 10;

	char* p1a1 = (char*)calloc(num_letters, sizeof(char));
	p1a1[0] = 'a';
	p1a1[1] = 'b';

	char* p1a2 = (char*)calloc(num_letters, sizeof(char));
	p1a2[0] = 'b';
	p1a2[1] = 'b';
	p1a2[2] = 'a';
	p1a2[3] = 'b';

	char* p1b1 = (char*)calloc(num_letters, sizeof(char));
	p1b1[0] = 'a';
	p1b1[1] = 'b';

	char* p1b2 = (char*)calloc(num_letters, sizeof(char));
	p1b2[0] = 'b';
	p1b2[1] = 'b';
	p1b2[2] = 'a';
	p1b2[3] = 'b';

	char* p1c1 = (char*)calloc(num_letters, sizeof(char));
	p1c1[0] = '1';
	p1c1[1] = '1';

	char* p1c2 = (char*)calloc(num_letters, sizeof(char));
	p1c2[0] = '0';
	p1c2[1] = '0';
	p1c2[2] = '1';
	p1c2[3] = '0';

	char* p1c3 = (char*)calloc(num_letters, sizeof(char));
	p1c3[0] = '0';
	p1c3[1] = '0';

	char* p1d1 = (char*)calloc(num_letters, sizeof(char));
	p1d1[0] = '0';
	p1d1[1] = '0';
	p1d1[2] = '1';
	p1d1[3] = '1';

	char* p1d2 = (char*)calloc(num_letters, sizeof(char));
	p1d2[0] = '1';
	p1d2[1] = '0';
	p1d2[2] = '1';
	p1d2[3] = '1';

	char* p1e1 = (char*)calloc(num_letters, sizeof(char));
	p1e1[0] = '1';
	p1e1[1] = '0';
	p1e1[2] = '1';
	p1e1[3] = '1';

	char* p1e2 = (char*)calloc(num_letters, sizeof(char));
	p1e2[0] = '0';
	p1e2[1] = '0';
	p1e2[2] = '1';
	p1e2[3] = '1';

	char* p2a1 = (char*)calloc(num_letters, sizeof(char));
	p2a1[0] = 'm';
	p2a1[1] = 'a';
	p2a1[2] = 'n';
	p2a1[3] = 'b';

	char* p2a2 = (char*)calloc(num_letters, sizeof(char));
	p2a2[0] = 'b';
	p2a2[1] = 'm';
	p2a2[2] = 'a';
	p2a2[3] = 'n';

	char* letters = (char*)calloc(num_letters, sizeof(char));
	letters[0] = 'w';
	letters[1] = 'a';
	letters[2] = 's';
	letters[3] = 'h';
	letters[4] = 'i';
	letters[5] = 'd';
	letters[6] = 'g';
	letters[7] = 't';
	letters[8] = 'o';
	letters[9] = 'a';

	char* letters2 = (char*)calloc(num_letters, sizeof(char));
	letters2[0] = 'w';
	letters2[1] = 'a';
	letters2[2] = 's';
	letters2[3] = 'h';
	letters2[4] = 'i';
	letters2[5] = 'n';
	letters2[6] = 'g';
	letters2[7] = 't';
	letters2[8] = 'o';
	letters2[9] = 'n';

	char* p2c1 = (char*)calloc(num_letters, sizeof(char));
	p2c1[0] = 'm';
	p2c1[1] = 'a';
	p2c1[2] = 'n';
	p2c1[3] = 'b';

	char* p2c2 = (char*)calloc(num_letters, sizeof(char));
	p2c2[0] = 'b';
	p2c2[1] = 'm';
	p2c2[2] = 'a';
	p2c2[3] = 'n';

	printf("1a testing 'ab'\n");
	int r1 = DFA_execute(makePart1a(), p1a1);
	printf("Result %d\n", r1);

	printf("1a testing 'bbab'\n");
	int r2 = DFA_execute(makePart1a(), p1a2);
	printf("Result %d\n", r2);

	printf("1b testing 'ab'\n");
	int r3 = DFA_execute(makePart1b(), p1b1);
	printf("Result %d\n", r3);

	printf("1b testing 'bbab'\n");
	int r4 = DFA_execute(makePart1b(), p1b2);
	printf("Result %d\n", r4);

	printf("1c testing '11'\n");
	int r5 = DFA_execute(makePart1c(), p1c1);
	printf("Result %d\n", r5);

	printf("1c testing '0010'\n");
	int r6 = DFA_execute(makePart1c(), p1c2);
	printf("Result %d\n", r6);

	printf("1d testing '0011'\n");
	int r8 = DFA_execute(makePart1d(), p1d1);
	printf("Result %d\n", r8);

	printf("1d testing '1011'\n");
	int r9 = DFA_execute(makePart1d(), p1d2);
	printf("Result %d\n", r9);

	printf("1e testing '1011'\n");
	int r10 = DFA_execute(makePart1e(), p1e1);
	printf("Result %d\n", r10);

	printf("1e testing '0011'\n");
	int r11 = DFA_execute(makePart1e(), p1e2);
	printf("Result %d\n", r11);
	printf("\n\n");

	printf("2a testing 'manb'\n");
	int n1 = execute(makePart2a(), p2a1);
	printf("Result %d\n", n1);

	printf("2a testing 'bman'\n");
	int n2 = execute(makePart2a(), p2a2);
	printf("Result %d\n", n2);

	printf("2b testing 'washidgtoa'\n");
	int n3 = execute(makePart2b(), letters);
	printf("Result %d\n", n3);

	printf("2b testing 'washington'\n");
	int n4 = execute(makePart2b(), letters2);
	printf("Result %d\n", n4);

	printf("2c testing 'manb'\n");
	int n5 = execute(makePart2c(), p2c1);
	printf("Result %d\n", n5);

	printf("2c testing 'bman'\n");
	int n6 = execute(makePart2c(), p2c2);
	printf("Result %d\n", n6);

	printf("3a testing 'manb'\n");
	int nfa2dfa1 = DFA_execute(makeIntoDFA(makePart2a()), p2a1);
	printf("Result %d\n", nfa2dfa1);

	printf("3a testing 'bman'\n");
	int nfa2dfa2 = DFA_execute(makeIntoDFA(makePart2a()), p2a2);
	printf("Result %d\n", nfa2dfa2);



	//THIS TAKES A LONG TIME TO RUN
	printf("3b testing 'washidgtoa'\n");
	int nfa2dfa3 = DFA_execute(makeIntoDFA(makePart2b()), letters);
	printf("Result %d\n", nfa2dfa3);

	printf("3b testing 'washington'\n");
	int nfa2dfa4 = DFA_execute(makeIntoDFA(makePart2b()), letters2);
	printf("Result %d\n", nfa2dfa4);
	//END OF LONG RUNTIME CODE



	printf("3c testing 'manb'\n");
	int nfa2dfa5 = DFA_execute(makeIntoDFA(makePart2c()), p2c1);
	printf("Result %d\n", nfa2dfa5);

	printf("3c testing 'bman'\n");
	int nfa2dfa6 = DFA_execute(makeIntoDFA(makePart2c()), p2c2);
	printf("Result %d\n", nfa2dfa6);


	//printf("\n\n\n\n\tInput matches    '1' is accepted  '-1' is not accepted\n dfa 1\t%d\n dfa 2\t%d\n dfa 3\t%d\n dfa 4\t%d\n dfa 5\t%d", r1, r2, r3, r4, r5);

	printf("\n\n");
	//FUCK THIS STUPI ASS N2 PEACE OF SHIT
	//	int n2 = execute(makePart2b(), letters);
	//	int n3 = execute(makePart2c(), letters);
	//printf("\n\n\n\tInput matches    '1' is accepted  '-1' is not accepted\n nfa 1\t%d\n nfa 2\t%d\n nfa 3\t%d", n1, n2, n3);

//
//	int nfa2dfa1 = DFA_execute(makeIntoDFA(makePart2a()), letters);
//	int nfa2dfa2 = DFA_execute(makeIntoDFA(makePart2b()), letters);
//	int nfa2dfa3 = DFA_execute(makeIntoDFA(makePart2c()), letters);

	//printf("\n\n\n\tInput matches    '1' is accepted  '-1' is not accepted\n n2d 1\t%d\n n2d 2\t%d\n n2d 3\t%d", nfa2dfa1, nfa2dfa2, nfa2dfa3);




}

