#include "adjacencymatrix.h"
#include <iostream>
#include <queue>

namespace myalgorithm {

AdjacencyMatrix::AdjacencyMatrix(const size_t node_size)
	: node_size_(node_size),
		graph_(node_size, std::vector<int>(node_size, 0)) {}

bool AdjacencyMatrix::UpdateEdge(const size_t node_out,
															const size_t node_in, 
															const int weight) {
	if (node_out >= node_size_ || node_in >= node_size_ ||
			weight <= 0) {
		return false;
	}

	graph_[node_out][node_in] = weight;
	return true;
}

bool AdjacencyMatrix::DeleteEdge(const size_t node_out,
																 const size_t node_in) {
	if (node_out >= node_size_ || node_in >= node_size_ ||
			graph_[node_out][node_in] == 0) {
		return false;
	}

	graph_[node_out][node_in] = 0;
	return true;
}

void AdjacencyMatrix::Show() const {
	for (int i = 0; i < node_size_; ++i) {
		std::cout << "\t" << i;
	}
	std::cout << std::endl;

	for (int i = 0; i < node_size_; ++i) {
		std::cout << i << ":\t";
		for (const auto& weight : graph_[i]) {
			std::cout << weight << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void AdjacencyMatrix::DFS(const size_t start_vertex,
													std::vector<size_t>& ret_vertices) const {
	if (start_vertex >= node_size_)
		return;
	std::vector<bool> is_visited(node_size_, false);
	DFS(start_vertex, ret_vertices, is_visited);
}

void AdjacencyMatrix::DFS(const size_t start_vertex,
	std::vector<size_t>& ret_vertices,
	std::vector<bool>& is_visited) const {
	is_visited[start_vertex] = true;
	ret_vertices.push_back(start_vertex);

	for (size_t i = 0; i < node_size_; ++i) {
		if (graph_[start_vertex][i] > 0 && !is_visited[i]) {
			DFS(i, ret_vertices, is_visited);
		}
	}
}

void AdjacencyMatrix::BFS(const size_t start_vertex,
													std::vector<size_t>& ret_vertices) const {
	if (start_vertex >= node_size_)
		return;
	std::vector<bool> is_visited(node_size_, false);

	std::queue<size_t> queue_vertex;
	is_visited[start_vertex] = true;
	queue_vertex.push(start_vertex);

	while (!queue_vertex.empty()) {
		int queue_len = queue_vertex.size();
		for (int i = 0; i < queue_len; ++i) {
			size_t vertex = queue_vertex.front();
			queue_vertex.pop();
			ret_vertices.push_back(vertex);

			for (int i = 0; i < node_size_; ++i) {
				if (graph_[vertex][i] > 0 && !is_visited[i]) {
					is_visited[i] = true;
					queue_vertex.push(i);
				}
			}
		}
	}
}

}