#pragma once
#include <vector>

template <typename T>
struct Node{
        T val;
        Node<T>* left;
        Node<T>* right;

        Node(T val){
            this->val = val;
            left = nullptr;
            right = nullptr;
        }

        ~Node(){
            if (left) delete left;
            if (right) delete right;
        }
};

template <typename T>
class Segtree{
    private:
        std::vector<T> tree;
        int arrsize;
    
    public:
        Segtree(std::vector<T> vals): tree(vals.size() * 4){
            arrsize = vals.size();

            // build tree
            build(vals, 1, 0, vals.size() - 1);
        }

        void build(std::vector<T>& vals, int v, int lh, int rh){
            /*Build the segment tree*/
            if (lh == rh){
                tree[v] = vals[lh];
            }
            else{
                int mid = (lh + rh) / 2;
                // build children
                build(vals, v * 2, lh, mid);
                build(vals, v * 2 + 1, mid + 1, rh);
                tree[v] = tree[v * 2] + tree[v * 2 + 1];
            }
        }

        T sum(int lh, int rh){
            return sum_(1, 0, this->arrsize - 1, lh, rh);
        }

        void update(int pos, int val){
            update_(1, 0, this->arrsize - 1, pos, val);
        }

        std::vector<T> getTree(){
            return tree;
        }

        T sum_(int v, int lh, int rh, int tlh, int trh){
            /*Sum the values between [tlh, trh] inclusive*/
            if (tlh > trh) 
                return T();

            // interval matches exactly
            if (lh == tlh && rh == trh){
                return tree[v];
            }

            // otherwise, use recursion
            else{
                int mid = (lh + rh) / 2;
                return sum_(v * 2, lh, mid, tlh, std::min(mid, trh))
                    + sum_(v * 2 + 1, mid + 1, rh, std::max(mid + 1, tlh), trh);
            }
        }

        void update_(int v, int lh, int rh, int pos, int val){
            if (lh == rh){
                tree[v] = val;
            } 
            else{
                int mid = (lh + rh) / 2;
                if (pos <= mid){
                    update_(v * 2, lh, mid, pos, val);
                }
                else{
                    update_(v * 2 + 1, mid + 1, rh, pos, val);
                }
                
                tree[v] = tree[v * 2] + tree[v * 2 + 1];
            }
        }


        int get_parent(int idx){
            return idx / 2;
        }

        int get_left(int idx){
            return idx * 2;
        }

        int get_right(int idx){
            return idx * 2 + 1;
        }

};