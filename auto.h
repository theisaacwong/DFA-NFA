/*
 * auto.h
 *
 *  Created on: Sep 21, 2017
 *      Author: Isaac
 */

#ifndef AUTO_H_
#define AUTO_H_


typedef struct {
	int isAccepting;
	int transitions[128];
} DFA_state;

typedef struct {
	int numStates;
	DFA_state *states;
}DFA;

typedef struct{
	int ***states;
	int *acceptingStates;
	int nstates;
} NFA;


extern DFA* makeIntoDFA(NFA* nfa);

extern DFA* DFA_new(int nstates);
extern void DFA_free(DFA *dfa);
extern int DFA_get_size(DFA *dfa);
extern int DFA_get_transition(DFA *dfa, int src, char sym);
extern void DFA_set_transition(DFA *dfa, int src, char sym, int dst);
extern void DFA_set_transition_str(DFA *dfa, int src, char *str, int dst);
extern void DFA_set_transition_all(DFA *dfa, int src, int dst);
extern void DFA_set_accepting(DFA *dfa, int state, int value);
extern int DFA_get_accepting(DFA *dfa, int state);
extern int DFA_execute(DFA *dfa, char *input);
extern void DFA_print(DFA *dfa);

extern int*** threeDmalloc(int x, int y, int z);

extern DFA* makePart1a();
extern DFA* makePart1b();
extern DFA* makePart1c();
extern DFA* makePart1d();
extern DFA* makePart1e();
extern NFA* makePart2b();

extern NFA* makePart2a();

extern NFA* makePart2c();

extern NFA* NFA_new(int nstates);

extern int recur(NFA* nfa, int startState, char* input);
extern int max(int i, int k);

extern int execute(NFA* nfa, char* input);

extern NFA* makeNFA();

extern void NFA_free(NFA* nfa);

/**
 * Free the given NFA.
 */
extern void NFA_free(NFA* nfa);

/**
 * Return the number of states in the given NFA.
 */
extern int NFA_get_size(NFA nfa);

/**
 * Return the set of next states specified by the given NFA's transition
 * function from the given state on input symbol sym.
 */
//extern IntSet NFA_get_transitions(NFA nfa, int state, char sym);

/**
 * For the given NFA, add the state dst to the set of next states from
 * state src on input symbol sym.
 */
extern void NFA_add_transition(NFA nfa, int src, char sym, int dst);

/**
 * Add a transition for the given NFA for each symbol in the given str.
 */
extern void NFA_add_transition_str(NFA nfa, int src, char *str, int dst);

/**
 * Add a transition for the given NFA for each input symbol.
 */
extern void NFA_add_transition_all(NFA nfa, int src, int dst);

/**
 * Set whether the given NFA's state is accepting or not.
 */
extern void NFA_set_accepting(NFA nfa, int state, int value);

/**
 * Return true if the given NFA's state is an accepting state.
 */
extern int NFA_get_accepting(NFA nfa, int state);

/**
 * Run the given NFA on the given input string, and return true if it accepts
 * the input, otherwise false.
 */
extern int NFA_execute(NFA nfa, char *input);

/**
 * Print the given NFA to System.out.
 */
extern void NFA_print(NFA nfa);


#endif /* AUTO_H_ */
