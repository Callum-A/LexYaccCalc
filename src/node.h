#ifndef NODE_H
#define NODE_H

typedef struct Node Node;
typedef struct BinaryOp BinaryOp;
typedef struct Number Number;
typedef enum NodeType NodeType;

enum NodeType {
    BINARY_OP,
    NUM
};

struct BinaryOp {
    Node *left;
    Node *right;
    char op;
};

struct Number {
    double value;
};

struct Node {
    char *token;
    NodeType nodeType;
    union {
        BinaryOp *binaryOp;
        Number *number;
    } as;
};

#define IS_BINARY_OP(value) ((value)->nodeType == BINARY_OP)
#define IS_NUM(value) ((value)->nodeType == NUM)

Node *makeBinaryOp(Node *left, Node *right, char *token, char op);
Node *makeNumber(double value, char *token);

#endif