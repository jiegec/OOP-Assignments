#include "OptRouter.h"

#include <array>
#include <utility>

using namespace std;

const int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

void OptRouter::mazeBacktrace() {
  vector<array<int, 4>> weight(m_row * m_col, array<int, 4>({-1, -1, -1, -1}));
  list<pair<int, int>> nodes;
  weight[m_targetIndex].fill(0);
  int target_x, target_y;
  compXYIndex(m_targetIndex, target_x, target_y);
  for (int i = 0; i < 4; i++) {
    int next_x = target_x + dir[i][0];
    int next_y = target_y + dir[i][1];
    if (0 <= next_x && next_x < m_col && 0 <= next_y && next_y < m_row) {
      int next_index = compIndex(next_x, next_y);
        if (m_grids[next_index] != m_grids[m_targetIndex] - 1) {
            continue;
        }
      weight[next_index][i] = 1;
      nodes.push_back(pair<int, int>(next_index, i));
    }
  }
 
  // dijkstra-like minimum turns finding
  while (nodes.size()) {
    pair<int, int> current_node = nodes.front();
    nodes.pop_front();
    int current_x, current_y;
    compXYIndex(current_node.first, current_x, current_y);
    for (int i = 0; i < 4; i++) {
      int next_x = current_x + dir[i][0];
      int next_y = current_y + dir[i][1];
      if (0 <= next_x && next_x < m_col && 0 <= next_y && next_y < m_row) {
        int next_index = compIndex(next_x, next_y);
        if (m_grids[next_index] != m_grids[current_node.first] - 1) {
            continue;
        }
        int new_weight = weight[current_node.first][current_node.second] + (i != current_node.second);
        if (new_weight < weight[next_index][i] || weight[next_index][i] == -1) {
            weight[next_index][i] = new_weight;
            nodes.push_back(pair<int,int>(next_index,i));
        }
      }
    }
  }

  int min_weight = weight[m_sourceIndex][0];
  int min_weight_dir = 0;
  for (int i = 1;i < 4;i++) {
      if (min_weight > weight[m_sourceIndex][i] && weight[m_sourceIndex][i] != -1) {
          min_weight = weight[m_sourceIndex][i];
          min_weight_dir = i;
      }
  }

  // find the path
  printf("Found path with least turns:");
  int current_index = m_sourceIndex;
  int current_direction = min_weight_dir;
  int current_turns = min_weight;
  while(1) {
      int current_x, current_y;
      compXYIndex(current_index, current_x, current_y);
      printf(" [%d,%d]", current_x, current_y);
      // 3-current_direction means the opposite direction
      int prev_x = current_x + dir[3-current_direction][0],
          prev_y = current_y + dir[3-current_direction][1];
      int prev_index = compIndex(prev_x, prev_y);
      if (prev_index == m_targetIndex) {
      printf(" [%d,%d]\n", prev_x, prev_y);
      break;
      }
      // find the direction of prev
      for (int i = 0;i < 4;i++) {
          if (current_turns == (weight[prev_index][i] + (i != current_direction))) {
              current_turns = weight[prev_index][i];
              current_index = prev_index;
              current_direction = i;
              break;
          }
      }
  }
  };

// directly copied from BaseRouter
bool OptRouter::route(void) {
  if (this->m_sourceIndex < 0 || this->m_targetIndex < 0 || this->m_row <= 0 ||
      this->m_col <= 0)
    return false;

  this->m_path.clear();

  // initialize the cost of the source grid
  m_grids[this->m_sourceIndex] = 0;

  // maze expansion
  if (mazeSearch()) {
    mazeBacktrace();
    return true;
  } else
    return false;
}
