#pragma once
#include <vector>
#include <stdexcept>

template <typename T, typename Accumulator = std::plus<T>>
class seg_tree{
    private:
        std::vector<T> tree;
        size_t size_;
        Accumulator accumulator;
    
    public:
        seg_tree(std::vector<T> vals): tree(vals.size() * 4), size_(vals.size()) {

            // build tree
            build_(vals, 1, 0, this->size_ - 1);
        }
        seg_tree(size_t size): tree(size * 4), size_(size) {}

        /**
         * Take the sum from lh to rh inclusive
        */
        const T sum(int lh, int rh) const {
            if (lh < 0 || rh >= size_) {
                throw std::runtime_error("range of [" + std::to_string(lh) + ", " + std::to_string(rh) + "] invalid, must be within [0, " + std::to_string(size_ - 1) + "]");
            }
            return sum_(1, 0, this->size_ - 1, lh, rh);
        }

        /**
         * Update is 0 indexed
        */
        void update(int pos, int val) {
            update_(1, 0, this->size_ - 1, pos, val);
        }

        std::vector<T> getTree() const {
            return tree;
        }

        const size_t size() const {
            return size_;
        }

        void build_(std::vector<T>& vals, int v, int lh, int rh) {
            /*Build the segment tree*/
            if (lh == rh) {
                tree[v] = vals[lh];
            }
            else{
                int mid = (lh + rh) / 2;
                // build children
                build_(vals, get_left(v), lh, mid);
                build_(vals, get_right(v), mid + 1, rh);
                tree[v] = accumulator(tree[get_left(v)], tree[get_right(v)]);
            }
        }

        /**
         * Accumulate between the range tlh and trh
         * lh & rh: the interval of the list currently being searched
         * tlh & trh: the interval of the underlying list we're trying to accumulate on
        */
        const T sum_ (int v, int lh, int rh, int tlh, int trh) const {
            /*Sum the values between [tlh, trh] inclusive*/
            if (tlh > trh) 
                return T();

            // interval matches exactly
            if (lh == tlh && rh == trh) {
                return tree[v];
            }

            // otherwise, use recursion
            else {
                int mid = (lh + rh) / 2;
                return accumulator(sum_(get_left(v), lh, mid, tlh, std::min(mid, trh)),
                    sum_(get_right(v), mid + 1, rh, std::max(mid + 1, tlh), trh));
            }
        }

        void update_(int v, int lh, int rh, int pos, int val) {
            if (lh == rh) {
                tree[v] = val;
            } 
            else{
                int mid = (lh + rh) / 2;
                if (pos <= mid) {
                    update_(get_left(v), lh, mid, pos, val);
                }
                else{
                    update_(get_right(v), mid + 1, rh, pos, val);
                }
                
                tree[v] = accumulator(tree[get_left(v)], tree[get_right(v)]);
            }
        }


        int get_parent(int idx) const {
            return idx / 2;
        }

        int get_left(int idx) const {
            return idx * 2;
        }

        int get_right(int idx) const {
            return idx * 2 + 1;
        }

};