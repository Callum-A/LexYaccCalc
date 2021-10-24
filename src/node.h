#ifndef NODE_H
#define NODE_H

typedef struct Node Node;
typedef struct BinaryOp BinaryOp;
typedef struct Number Number;
typedef struct Boolean Boolean;
typedef struct NodeList NodeList;
typedef struct Program Program;
typedef enum NodeType NodeType;

enum NodeType { BINARY_OP, BOOLEAN, NUM, PROGRAM };

struct NodeList {
    int count;
    int capacity;
    Node *nodes;
};

struct Program {
    NodeList *stmts;
};

struct BinaryOp {
    Node *left;
    Node *right;
    char op;
};

struct Number {
    double value;
};

struct Boolean {
    int value; // 0 or 1
};

struct Node {
    char *token;
    NodeType nodeType;
    union {
        BinaryOp *binaryOp;
        Number *number;
        Boolean *boolean;
        Program *program;
    } as;
};

#define IS_BINARY_OP(value) ((value)->nodeType == BINARY_OP)
#define IS_NUM(value) ((value)->nodeType == NUM)
#define IS_BOOLEAN(value) ((value)->nodeType == BOOLEAN)

Node *makeBinaryOp(Node *left, Node *right, char *token, char op);
Node *makeNumber(double value, char *token);
Node *makeTrue(char *token);
Node *makeFalse(char *token);
Node *makeProgram(char *token);
void addNodeToProgram(Node *program, Node *nodeToAdd);

#endif