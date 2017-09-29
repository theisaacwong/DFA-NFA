Brandon Smart and Isaac Wong

How to build project: In terminal, go to the project folder, then type ‘make’. ie
[User]$ make 

Once you build the project, you’ll see a series of tests. We tested each part twice to show an accepting test and a non accepting test. Negative value means it did not accept (i.e -1) and non negative values mean it accepted it (0 or 1). 

**IMPORTANT** We currently have the following lines uncommented:

	//THIS TAKES A LONG TIME TO RUN
	printf("3b testing 'washidgtoa'\n");
	int nfa2dfa3 = DFA_execute(makeIntoDFA(makePart2b()), letters);
	printf("Result %d\n", nfa2dfa3);

	printf("3b testing 'washington'\n");
	int nfa2dfa4 = DFA_execute(makeIntoDFA(makePart2b()), letters2);
	printf("Result %d\n", nfa2dfa4);
	//END OF LONG RUNTIME CODE

The run time for this code is very very large so we recommend commenting this part out while you test the other parts. It will work though, it will just take a while. 

The only trouble we ran into was with Question 2 part b. On input ‘washington’ we are getting a result of 1 which means it’s accepting it. However, on other inputs we get the correct result (i.e accepting). We had TA Alex look into this problem and he could not identify any issues with our code. We are hoping that once you look at the code you will determine the same thing and we will be able to receive close to full credit for this part, but at the very least Alex said we would receive partial credit. Another interesting phenomenon is that when we turn nfa ‘washington’ into a dfa, it works! This puzzled us and Alex so we are interested in hearing your feedback!

Our NFA structure is a 3D array with NFA[source state][input char][destination source] = 1/-1. 1 meaning there is a path from the source state to the destination state on input char. The accepting states are stored in another array with each index representing the state and the value at that index (1/-1) stating if it is accepting or not. 

The code was tested on Windows 10 Enterprise Edition, on Red Hat Enterprise Linux Server release 6.6 (Santiago).
