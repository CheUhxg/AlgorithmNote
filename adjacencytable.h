#ifndef ADJACENCY_TABLE_H_
#define ADJACENCY_TABLE_H_

#include <vector>
#include <list>

namespace myalgorithm {
	class AdjacencyTable
	{
	private:
		struct Node
		{
			int weight_;
			size_t vertex_;
			explicit Node(const int weight, const size_t vertex)
				: weight_(weight), vertex_(vertex) {}
		};

		std::vector<std::list<Node>> table_;
		size_t node_size_;

		bool HasEdge(const size_t node_out, const size_t node_in) const;
		void DFS(const size_t start_vertex, 
						 std::vector<size_t>& ret_vertices,
						 std::vector<bool>& is_visited) const;
	public:
		explicit AdjacencyTable(const size_t node_size);

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

#endif	//	ADJACENCY_TABLE_H_