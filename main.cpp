#include "Utility.h"
#include "Graph.h"

void print_usage() {
	printf("Usage: [1]exe [2]alg [3]graph-dir\n");
	printf("\talg: greedy, greedy_dynamic, BDOne, BDTwo, LinearTime, NearLinear\n");
}

int main(int argc, char *argv[]) {
	if(argc < 3) {
		print_usage();
		return 0;
	}

#ifndef NDEBUG
	printf("**** MIS (Debug): %s, %s *** ", argv[2], argv[1]);
#else
	printf("**** MIS (Release): %s, %s *** ", argv[2], argv[1]);
#endif

	printf("\n");

#ifdef _LINUX_
	struct timeval start, end1, end;
	gettimeofday(&start, NULL);
#endif

	Graph *graph = new Graph(argv[2]);
	graph->read_graph();

#ifdef _LINUX_
	gettimeofday(&end1, NULL);

	long long mtime1, seconds1, useconds1;
	seconds1 = end1.tv_sec - start.tv_sec;
	useconds1 = end1.tv_usec - start.tv_usec;
	mtime1 = seconds1*1000000 + useconds1;
#endif

	if(strcmp(argv[1], "greedy") == 0) graph->greedy();
	else if(strcmp(argv[1], "greedy_dynamic") == 0) graph->greedy_dynamic();
	else if(strcmp(argv[1], "BDOne") == 0) graph->degree_one_kernal_and_remove_max_degree();
	else if(strcmp(argv[1], "BDTwo") == 0) graph->degree_two_kernal_and_remove_max_degree_with_contraction();
	else if(strcmp(argv[1], "LinearTime") == 0) graph->degree_two_kernal_and_remove_max_degree_without_contraction();
	else if(strcmp(argv[1], "NearLinear") == 0) graph->degree_two_kernal_dominate_lp_and_remove_max_degree_without_contraction();
	else print_usage();

#ifdef _LINUX_
	gettimeofday(&end, NULL);

	long long mtime, seconds, useconds;
	seconds = end.tv_sec - start.tv_sec;
	useconds = end.tv_usec - start.tv_usec;
	mtime = seconds*1000000 + useconds;

	//printf("Total time excluding IO is: %lld\n", mtime-mtime1);
#endif

	return 0;
}
