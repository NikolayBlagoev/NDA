#pragma once
#include <vector>
#include <cmath>
namespace nda{
    template<typename T>
    class vec{
        public:
            
            inline ~vec(){
                std::vector<T>().swap(data);
            }
            inline vec() {
                capacity = 0;
                data = std::vector<T>();
            }
            inline size_t size() const{
                return capacity;
            }

            inline vec(size_t sz) {
                capacity = sz;
                data = std::vector<T>(sz);
            }

            inline vec(size_t sz, T fl) {
                capacity = sz;
                data = std::vector<T>();
                for(size_t i = 0; i < sz; i++){
                    data.push_back(fl);
                }
            }

            inline void expand(size_t sz) {
                while(capacity < sz){
                    data.push_back(0);
                    capacity += 1;
                }
                
            }
            inline T& operator[](size_t i){
                return data[i];
            }

            inline T operator[](size_t i) const{
                return data[i];
            }

            inline T operator()(size_t i) const{
                return data[i];
            }
            
            inline T& get(size_t i){
                return data[i];
            }

            inline vec<T>& operator=(const nda::vec<T>& u){
                for(size_t i = 0; i < capacity; i++){
                    if(i >= u.size()){
                        break;
                    }
                    data[i] = u[i];
                            
                }
                return *this;
            }

            inline T l1norm(){
                if(capacity == 0){
                    return 0;
                }
                T ret = std::abs(data[0]);
                for(int i = 1; i < capacity; i ++){
                    ret += std::abs(data[i]);
                }
                return ret;
            }

            inline T l2norm(){
                if(capacity == 0){
                    return 0;
                }
                T ret = std::pow(data[0],2);
                for(int i = 1; i < capacity; i ++){
                    ret += std::pow(data[i],2);
                }
                return std::sqrt(ret);
            }

            inline void normalise(){
                if(capacity == 0){
                    return;
                }
                T norm = l2norm();
                for(int i = 0; i < capacity; i ++){
                    data[i] /= norm;
                }
            }
            
        private:
            size_t capacity;
            std::vector<T> data;
    };


    // Binary vector operations :
    template<typename T>
    inline vec<T> operator+(vec<T> v, vec<T> u){
        size_t max_cap = v.size() > u.size() ? v.size() : u.size();
        nda::vec<T> ret(max_cap);
        for(size_t i = 0; i < max_cap; i++){
            if(i >= v.size()){
                ret[i] = u[i];
            }else if(i >= u.size()){
                ret[i] = v[i];
            }else{
                ret[i] = v[i] + u[i];
            }
                    
        }
        return ret;
    }

    template<typename T, typename Q>
    inline vec<T> operator-(vec<T> v, vec<Q> u){
        size_t max_cap = v.size();
        nda::vec<T> ret(max_cap);
        for(size_t i = 0; i < max_cap; i++){
            if(i >= u.size()){
                ret[i] = v[i];
            }else{
                ret[i] = v[i] - u[i];
            }
                    
        }
        return ret;
    }

    // Unary vector operations :
    template<typename T>
    inline vec<T> operator-(vec<T> v){
        nda::vec<T> ret(v.size());
        for(size_t i = 0; i < v.size(); i++){
            ret[i] = -v[i];
                    
        }
        return ret;
    }


    // Binary vector and scalar :
    template<typename T, typename Q>
    inline vec<T> operator+(Q v, vec<T> u){
        
        nda::vec<T> ret(u.size());
        for(size_t i = 0; i < u.size(); i++){
            ret[i] = v + u[i];
                    
        }
        return ret;
    }
    
    template<typename T, typename Q>
    inline vec<T> operator+(vec<T> v, Q u){
        
        return u + v;
    }

    template<typename T, typename Q>
    inline vec<T> operator-(Q v, vec<T> u){
        nda::vec<T> ret(u.size());
        for(size_t i = 0; i < u.size(); i++){
            ret[i] = v - u[i];
                    
        }
        return ret;
    }

    template<typename T, typename Q>
    inline vec<T> operator-(vec<T> v, Q u){
        nda::vec<T> ret(u.size());
        for(size_t i = 0; i < u.size(); i++){
            ret[i] = v[i] - u;
                    
        }
        return ret;
    }
    
}