#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "Utility.h"

using namespace std;

struct Edge {
	int id, duplicate;
	int next;
};

class Graph {
private:
	string dir; //input graph directory
	ui n, m; //number of nodes and edges of the graph

	ui *pstart; //offset of neighbors of nodes
	ui *edges; //adjacent ids of edges

public:
	Graph(const char *_dir) ;
	~Graph() ;

	void read_graph() ;
	void degree_one_kernal_and_remove_max_degree() ;
	void degree_two_kernal_and_remove_max_degree_with_contraction() ;
	void degree_two_kernal_and_remove_max_degree_without_contraction() ;
	void degree_two_kernal_dominate_lp_and_remove_max_degree_without_contraction() ;

	void greedy() ;
	void greedy_dynamic() ;

private:
	int general_swap(char *is, char *fixed = NULL) ;
	void check_is(const char *is, int count) ;
	void compute_upperbound(const char *is, char *fixed = NULL) ;

	void get_two_neighbors(ui u, char *is, ui &u1, ui &u2) ;
	ui get_other_neighbor(ui u, char *is, ui u1) ;
	int exist_edge(ui u1, ui u2) ;
	void edge_rewire(ui u, ui u1, ui u2) ;

	int exist_edge(ui u, ui v, const ui *pend) ;
	int find_other_endpoint(ui u, ui v, char *is) ;
	ui edge_rewire(ui u, const ui *pend, ui v, ui w) ;

	int remove_degree_one_two(vector<ui> &degree_ones, vector<ui> &degree_twos, char *is, int *degree, vector<pair<ui,ui> > &S) ;

	int initial_dominance_and_degree_two_remove(vector<ui> &degree_ones, vector<ui> &degree_twos, char *is, int *degree, char *adj, vector<pair<ui,ui> > &S) ;

	int lp_reduction(ui *ids, ui ids_n, char *is, int *degree) ;

	void shrink(ui u, ui &end, const char *is) ;
	void shrink(ui u, ui &end, const char *is, ui *tri) ;
	void update_triangle(ui u1, ui u2, ui *pend, char *is, char *adj, ui *tri, int *degree, char *dominate, vector<ui> &dominated) ;
	int dominated_check(ui u, ui *pend, char *is, ui *tri, int *degree) ;
	int compute_triangle_counts(ui *tri, ui *pend, char *adj, char *is, int *degree, char *dominate, vector<ui> &dominated) ;
	void construct_degree_increase(ui *ids) ;

	int delete_vertex(ui v, char *is, int *degree, vector<ui> &degree_ones) ;
	int delete_vertex(ui v, char *is, int *degree, vector<ui> &degree_ones, vector<ui> &degree_twos) ;
	int delete_vertex(ui v, const ui *pend, char *is, int *degree, vector<ui> &degree_ones, vector<ui> &degree_twos) ;
	int delete_vertex(ui u, ui *pend, char *is, vector<ui> &degree_twos, ui *tri, char *adj, int *degree, char *dominate, vector<ui> &dominated) ;
	int delete_vertex(ui v, char *is, int *degree, int *head, Edge *es, int *bin_head, int *bin_next, int *bin_pre, vector<ui> &degree_ones, vector<ui> &degree_twos) ;
};

#endif
