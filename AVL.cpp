#include "AVL.h"
#include "iostream"

AVL::AVL() : data(nullptr), bucket(0)
{
    data = new AVL_Node *[bucket];
    for (int i = 0; i < bucket; i++)
    {
        data[i] = nullptr;
    }
}

AVL::AVL(int b) : bucket(b)
{
    data = new AVL_Node *[bucket];
    for (int i = 0; i < bucket; i++)
    {
        data[i] = nullptr;
    }
}

int AVL::hash_fun(int key)
{
    return key % bucket;
}

int AVL::height(AVL_Node *node)
{
    return node ? node->height : -1;
}

// AVL_Node *AVL::update_height(AVL_Node *node)
void AVL::update_height(AVL_Node *node)
{
    if (node == nullptr)
    {
        return;
    }

    int lh = (node->left != nullptr) ? node->left->height : -1;
    int rh = (node->right != nullptr) ? node->right->height : -1;

    node->height = 1 + std::max(lh, rh);
}
AVL_Node *AVL::right_rotate(AVL_Node *ynode)
{
    AVL_Node *xnode = ynode->left;
    AVL_Node *tnode = xnode->right;

    xnode->right = ynode;
    ynode->left = tnode;

    update_height(ynode);
    update_height(xnode);

    return xnode;
}

AVL_Node *AVL::left_rotate(AVL_Node *xnode)
{
    AVL_Node *ynode = xnode->right;
    AVL_Node *tnode = ynode->left;

    ynode->left = xnode;
    xnode->right = tnode;

    update_height(xnode);
    update_height(ynode);

    return ynode;
}

int AVL::balance_factor(AVL_Node *node)
{
    if (node == nullptr)
    {
        return -1;
    }
    else
    {
        return height(node->left) - height(node->right);
    }
}

AVL_Node *AVL::private_insert(AVL_Node *node, int k, int v)
{
    if (node == nullptr)
    {
        AVL_Node *newNode = new AVL_Node(k, v);
        node = newNode;
        return node;
    }

    if (k < node->key)
    {
        node->left = private_insert(node->left, k, v);
    }
    else if (k > node->key)
    {
        node->right = private_insert(node->right, k, v);
    }
    else
    {
        node->value = v;
        return node;
    }

    update_height(node);

    int bf = balance_factor(node);

    if (bf > 1 && k < node->left->key)
    {
        return right_rotate(node);
    }

    if (bf < -1 && k > node->right->key)
    {
        return left_rotate(node);
    }

    if (bf > 1 && k > node->left->key)
    {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    if (bf < -1 && k < node->right->key)
    {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

void AVL::insert(int k, int v)
{
    int hash = hash_fun(k);
    data[hash] = private_insert(data[hash], k, v);

    if (data[hash] && data[hash]->height >= 10)
    {
        increase_bucket();
    }
}

AVL_Node *AVL::find_min(AVL_Node *node)
{
    AVL_Node *current = node;
    while (current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

AVL_Node *AVL::private_remove(AVL_Node *node, int k, int v)
{
    if (node == nullptr)
    {
        std::cout << "Tree is alredy empty\n";
        return nullptr;
    }

    if (k < node->key)
    {
        node->left = private_remove(node->left, k, v);
    }
    else if (k > node->key)
    {
        node->right = private_remove(node->right, k, v);
    }
    else
    {
        if (node->left == nullptr || node->right == nullptr)
        {
            AVL_Node *temp = node->left ? node->left : node->right;

            if (temp == nullptr)
            {
                temp = node;
                node = nullptr;
            }
            else
            {
                node = temp;
            }
            delete temp;
        }
        else
        {
            AVL_Node *temp = find_min(node->right);

            node->key = temp->key;
            node->value = temp->value;

            node->right = private_remove(node->right, temp->key, temp->value);
        }
    }

    if (node == nullptr)
    {
        return node;
    }

    update_height(node);

    int bf = balance_factor(node);

    if (bf > 1 && balance_factor(node->left) >= 0)
    {
        return right_rotate(node);
    }

    if (bf > 1 && balance_factor(node->left) < 0)
    {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    if (bf < -1 && balance_factor(node->right) <= 0)
    {
        return left_rotate(node);
    }

    if (bf < -1 && balance_factor(node->right) > 0)
    {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

void AVL::remove(int k, int v)
{
    int hash = hash_fun(k);
    data[hash] = private_remove(data[hash], k, v);
}

void AVL::print_all()
{
    for (int i = 0; i < bucket; i++)
    {
        std::cout << "[Bucket " << i << "]\n";
        print(data[i], 0);
        std::cout << std::endl;
    }
}

void AVL::print(AVL_Node *node, int depth)
{
    if (node == nullptr)
        return;

    print(node->right, depth + 1);

    for (int i = 0; i < depth; i++)
        std::cout << "    ";

    std::cout << "(key: " << node->key << ", val: " << node->value << ", h: " << node->height << ")\n";

    print(node->left, depth + 1);
}

void AVL::increase_bucket()
{
    int old_bucket = bucket;
    AVL_Node **old_data = data;

    bucket *= 2;
    data = new AVL_Node *[bucket];
    for (int i = 0; i < bucket; ++i)
    {
        data[i] = nullptr;
    }

    for (int i = 0; i < old_bucket; ++i)
    {
        reinsert_tree(old_data[i]);
    }

    for (int i = 0; i < old_bucket; ++i)
    {
        destroy_tree(old_data[i]);
    }

    delete[] old_data;
}

void AVL::reinsert_tree(AVL_Node *node)
{
    if (!node)
    {
        return;
    }
    reinsert_tree(node->left);
    reinsert_tree(node->right);
    insert(node->key, node->value);
}

void AVL::destroy_tree(AVL_Node *node)
{
    if (!node)
    {
        return;
    }
    destroy_tree(node->left);
    destroy_tree(node->right);
    delete node;
}
