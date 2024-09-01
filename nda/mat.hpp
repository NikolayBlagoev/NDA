#pragma once
#include <vector>
#include <cmath>
#include "vec.hpp"
namespace nda{
    template<typename T>
    class mat{
        public:
            
            inline ~mat(){
                std::vector<T>().swap(data);
            }
            inline mat(size_t dim_m, size_t dim_n) {
                n = dim_n;
                m = dim_m;
                data = std::vector<T>(dim_n * dim_m);
            }

            inline mat(size_t dim_m, size_t dim_n, T val) {
                n = dim_n;
                m = dim_m;
                data = std::vector<T>(dim_n * dim_m, val);
            }

            inline size_t width() const{
                return n;
            }

            inline size_t height() const{
                return m;
            }
            
            inline T operator()(size_t i, size_t j) const{
                return data[i*n + j];
            }

            inline T& operator()(size_t i, size_t j){
                return data[i*n + j];
            }
        private:
            size_t n;
            size_t m;
            std::vector<T> data;
    };

    template<typename T, typename Q>
    inline vec<T> operator*(mat<T> v, vec<Q> u){
        nda::vec<T> ret(v.height());
        size_t min_w = u.size() < v.width() ? u.size() : v.width();
        for(size_t i = 0; i < ret.size(); i++){
            for(size_t j = 0; j < min_w; j++){
                ret[i] += v(i,j)*u[j];
            }
            
        }
        return ret;
    }

    template<typename T>
    inline mat<T> identity(size_t n){
        nda::mat<T> ret = nda::mat<T>(n,n,0);
        for(size_t i = 0; i < n; i ++){
            ret(i,i) = (T) 1.0;
        }
        return ret;
    }


}