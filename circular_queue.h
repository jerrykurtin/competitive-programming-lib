#pragma once

template <typename T>
class circular_queue {
    private:
        T* vals;
        size_t front_;

        size_t size_;
        size_t capacity_;

        // allocates memory for double the current capacity
        void double_capacity() {
            T* newVals = new T[2 * capacity_];
            for (size_t idx = 0; idx < size_; ++idx){
                newVals[idx] = vals[(front_ + idx) % capacity_];
            }

            // reset vals
            delete [] vals;
            vals = newVals;
            capacity_ *= 2;
            front_ = 0;
        }
    
    public:
        circular_queue() {
            vals = new T[5];
            size_ = 0;
            capacity_ = 5;
        }
    
        ~circular_queue(){
            delete [] vals;
        }

        void push(T val){
            if (size_ == capacity_){
                double_capacity();
            }

            vals[(front_ + size_) % capacity_] = val;
            ++size_;
        }

        bool empty() const{
            return (size_ == 0);
        }

        T pop() {
            if (this->empty()){
                throw std::runtime_error("popping from an empty queue");
            }

            T ret = vals[front_];
            vals[front_] = -1;
            ++front_;
            --size_;
            if (front_ == capacity_)
                front_ = 0;
            
            return ret;
        }

        T front() const{
            if (this->empty()){
                throw std::runtime_error("querying an empty queue");
            }

            return vals[front_];
        }

        size_t size() const{ return size_; }
        size_t capacity() const{ return capacity_; }

};