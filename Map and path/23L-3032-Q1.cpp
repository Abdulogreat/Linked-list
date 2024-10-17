//#include <iostream>
//using namespace std;
//
//// Node class to represent each point on the map
//class Node {
//public:
//    Node* Left;
//    Node* Right;
//    Node* Up;
//    Node* Down;
//    string name;
//    bool isRoad;
//
//    // Constructor to initialize a node
//    Node() {
//        Left = Right = Up = Down = nullptr;
//        name = "";
//        isRoad = false;
//    }
//};
//
//// Map class to handle the grid of nodes
//class Map {
//public:
//    Node* head;   // Starting point (top-left corner)
//    int rows, cols; // Dimensions of the map
//
//    // Constructor to create a grid of nodes
//    Map(int rows, int cols) {
//        this->rows = rows;
//        this->cols = cols;
//        head = new Node();
//        createmap();
//    }
//
//    // Destructor to clean up the grid
//    ~Map() {
//
//        deletemap(head);
//    }
//
//    // Function to delete all nodes in the grid recursively
//    void deletemap(Node* node) {
//        if (!node) return;
//        Node* temp = node;
//        while (temp) {
//            Node* nextRow = temp->Down;
//            Node* current = temp;
//            while (current) {
//                Node* toDelete = current;
//                current = current->Right;
//                delete toDelete;
//            }
//            temp = nextRow;
//        }
//    }
//
//    // Function to initialize and connect the grid nodes
//    void createmap() {
//        Node* currentRowStart = head;
//        Node* prevRowStart = nullptr;
//
//        for (int i = 0; i < rows; i++) {
//            Node* current = currentRowStart;
//            Node* prev = nullptr;
//
//            for (int j = 0; j < cols; j++) {
//                if (prev) {
//                    prev->Right = current;
//                    current->Left = prev;
//                }
//                if (prevRowStart) {
//                    current->Up = prevRowStart;
//                    prevRowStart->Down = current;
//                    prevRowStart = prevRowStart->Right;
//                }
//                if (j < cols - 1) {
//                    current->Right = new Node();
//                    current->Right->Left = current;
//                }
//
//                prev = current;
//                current = current->Right;
//            }
//            prevRowStart = currentRowStart;
//            if (i < rows - 1) {
//                currentRowStart->Down = new Node();
//                currentRowStart = currentRowStart->Down;
//            }
//        }
//    }
//
//    // Function to find a node by row and column
//    Node* findNode(int row, int col) {
//        if (row < 0 || row >= rows || col < 0 || col >= cols) {
//            return nullptr;
//        }
//
//        Node* current = head;
//        for (int i = 0; i < row; i++) {
//            if (current) {
//                current = current->Down;
//            }
//        }
//
//        for (int j = 0; j < col; j++) {
//            if (current) {
//                current = current->Right;
//            }
//        }
//
//        return current;
//    }
//
//    // Function to construct a road starting at a specific row and column
//    void ConstructRoad(int row, int col, string pointA, string pointB, int lengthOfRoad, string direction) {
//        Node* start = findNode(row, col);
//        if (!start) {
//            cout << "Starting point not found!" << endl;
//            return;
//        }
//
//        start->name = pointA;
//        Node* current = start;
//
//        for (int i = 0; i < lengthOfRoad; i++) {
//            current->isRoad = true;
//
//            if (direction == "right" && current->Right) {
//                current = current->Right;
//            }
//            else if (direction == "left" && current->Left) {
//                current = current->Left;
//            }
//            else if (direction == "up" && current->Up) {
//                current = current->Up;
//            }
//            else if (direction == "down" && current->Down) {
//                current = current->Down;
//            }
//            else {
//                cout << "Cannot construct road in the given direction!" << endl;
//                return;
//            }
//        }
//
//        current->name = pointB;
//    }
//    // Function to remove the road between two points
//    void RemoveRoad(int row, int col, int lengthOfRoad, string direction) {
//        Node* start = findNode(row, col);
//        if (!start) {
//            cout << "Starting point not found!" << endl;
//            return;
//        }
//
//        Node* current = start;
//
//        for (int i = 0; i < lengthOfRoad; i++) {
//            current->isRoad = false;
//
//            if (direction == "right" && current->Right) {
//                current = current->Right;
//            }
//            else if (direction == "left" && current->Left) {
//                current = current->Left;
//            }
//            else if (direction == "up" && current->Up) {
//                current = current->Up;
//            }
//            else if (direction == "down" && current->Down) {
//                current = current->Down;
//            }
//            else {
//                cout << "Cannot remove road in the given direction!" << endl;
//                return;
//            }
//        }
//    }
//
//    // Function to print the map showing the roads
//    void PrintMap() {
//        Node* currentRow = head;
//        while (currentRow) {
//            Node* current = currentRow;
//            while (current) {
//                if (current->isRoad) {
//                    cout << "* ";
//                }
//                else {
//                    cout << "- ";
//                }
//                current = current->Right;
//            }
//            cout << endl;
//            currentRow = currentRow->Down;
//        }
//    }
//    // Function to print the path between two points
//    void PrintPath(int row, int col, int lengthOfRoad, string direction) {
//        Node* start = findNode(row, col);
//        if (!start) {
//            cout << "Starting point not found!" << endl;
//            return;
//        }
//
//        Node* current = start;
//
//        for (int i = 0; i < lengthOfRoad; i++) {
//            if (current->isRoad) {
//                cout << "* ";
//            }
//            else {
//                cout << "- ";
//            }
//
//            if (direction == "right" && current->Right) {
//                current = current->Right;
//            }
//            else if (direction == "left" && current->Left) {
//                current = current->Left;
//            }
//            else if (direction == "up" && current->Up) {
//                current = current->Up;
//            }
//            else if (direction == "down" && current->Down) {
//                current = current->Down;
//            }
//            else {
//                cout << "No direct path found!" << endl;
//                return;
//            }
//        }
//        cout << endl;
//    }
//};
//int main() {
//    Map myMap(3, 4);
//    myMap.ConstructRoad(0, 0, "A", "B", 3, "right");
//    cout << "Print1:" << endl;
//    myMap.PrintMap();
//    myMap.RemoveRoad(0, 0, 3, "right");
//    cout << "Print2: " << endl;
//    myMap.PrintMap();
//    myMap.ConstructRoad(0, 0, "A", "C", 2, "down");
//    cout << "Print3:" << endl;
//    myMap.PrintMap();
//    cout << "Print5: " << endl;
//    myMap.PrintPath(0, 0, 3, "down");
//
//    return 0;
//}
