#include "adjacencytable.h"
#include <iostream>
#include <queue>
#include <algorithm>

namespace myalgorithm {

AdjacencyTable::AdjacencyTable(const size_t node_size)
	: node_size_(node_size),
	table_(node_size, std::list<Node>()) {}

bool AdjacencyTable::HasEdge(const size_t node_out, const size_t node_in) const {
	for (const auto& node : table_[node_out]) {
		if (node.vertex_ == node_in)
			return true;
	}
	return false;
}

bool AdjacencyTable::UpdateEdge(const size_t node_out,
	const size_t node_in,
	const int weight) {
	if (node_out >= node_size_ || node_in >= node_size_ ||
			weight <= 0) {
		return false;
	}

	table_[node_out].push_back(Node(weight, node_in));
	return true;
}

bool AdjacencyTable::DeleteEdge(const size_t node_out, const size_t node_in) {
	if (node_out >= node_size_ || node_in >= node_size_ ||
			!HasEdge(node_out, node_in)) {
		return false;
	}

	for (auto iter = table_[node_out].begin();
			iter != table_[node_out].end();
			++iter) {
		if (iter->vertex_ == node_in) {
			table_[node_out].erase(iter);
			break;
		}
	}
	return true;
}

void AdjacencyTable::Show() const {
	for (int i = 0; i < node_size_; ++i) {
		std::cout << i << ":\t";
		for (const auto& node : table_[i]) {
			std::cout << node.vertex_ 
								<< "(" << node.weight_ << ")" << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void AdjacencyTable::DFS(const size_t start_vertex,
													std::vector<size_t>& ret_vertices) const {
	if (start_vertex >= node_size_)
		return;
	std::vector<bool> is_visited(node_size_, false);
	DFS(start_vertex, ret_vertices, is_visited);
}

void AdjacencyTable::DFS(const size_t start_vertex,
													std::vector<size_t>& ret_vertices,
													std::vector<bool>& is_visited) const {
	is_visited[start_vertex] = true;
	ret_vertices.push_back(start_vertex);

	for (const auto& node : table_[start_vertex]) {
		if (!is_visited[node.vertex_]) {
			DFS(node.vertex_, ret_vertices, is_visited);
		}
	}
}

void AdjacencyTable::BFS(const size_t start_vertex,
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

			for (const auto& next_node : table_[vertex]) {
				if (!is_visited[next_node.vertex_]) {
					is_visited[next_node.vertex_] = true;
					queue_vertex.push(next_node.vertex_);
				}
			}
		}
	}
}

void AdjacencyTable::Dijkstra(const size_t start_vertex,
															std::vector<size_t>& path,
															std::vector<int>& ret_weights) const {
	if (start_vertex >= node_size_)
		return;
	std::vector<bool> is_visited(node_size_, false);
	std::vector<int> distance(node_size_, 0x3fffffff);
	
	distance[start_vertex] = 0;
	for (int i = 0; i < node_size_; ++i) {
		size_t min_vertex = -1;
		for (int j = 0; j < node_size_; ++j) {
			if (is_visited[j] == false) {
				if (min_vertex == -1 ||
						distance[min_vertex] > distance[j]) {
					min_vertex = j;
				}
			}
		}
		is_visited[min_vertex] = true;
		path.push_back(min_vertex);
		for (const auto& node : table_[min_vertex]) {
			if (!is_visited[node.vertex_] &&
				node.weight_ + distance[min_vertex] < distance[node.vertex_]) {
				distance[node.vertex_] = node.weight_ + distance[min_vertex];
			}
		}
	}
	ret_weights.swap(distance);
}

}