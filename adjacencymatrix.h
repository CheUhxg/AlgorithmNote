#ifndef ADJACENCY_MATRIX_H_
#define ADJACENCY_MATRIX_H_

#include <vector>

namespace myalgorithm {
class AdjacencyMatrix
{
private:
	std::vector<std::vector<int>> graph_;
	size_t node_size_;

	void DFS(const size_t start_vertex,
		std::vector<size_t>& ret_vertices,
		std::vector<bool>& is_visited) const;
public:
	explicit AdjacencyMatrix(const size_t node_size);

	bool UpdateEdge(const size_t node_out, const size_t node_in, const int weight);
	bool DeleteEdge(const size_t node_out, const size_t node_in);

	void Show() const;

	void DFS(const size_t start_vertex,
					 std::vector<size_t>& ret_vertices) const;
	void BFS(const size_t start_vertex,
					 std::vector<size_t>& ret_vertices) const;
	void Dijkstra(const size_t start_vertex,
								std::vector<size_t>& path,
								std::vector<int>& ret_weights) const;
};
}

#endif	//	ADJACENCY_MATRIX_H_