/*
IMPLEMENTAÇÃO DO ALGORITMO JARVIS MARCH (GIFT WRAPPING)

COMPLEXIDADE DE TEMPO: O(nh), n é o número de pontos da entrada e h é o número de pontos do fecho convexo

IDEIA: É garantido que o ponto mais à esquerda vai fazer parte do fecho convexo.
Dado isso, a cada iteração definimos um endpoint qualquer e testamos pra todo ponto no conjunto de pontos, se o ponto está à
esquerda da linha formada pelo último ponto adicionado e o endpoint atual, se for verdade, o ponto atual será o novo endpoint.
O último endpoint definido será o ponto a ser adicionado nessa iteração, quando o o ponto a ser adicionado for igual ao primeiro ponto, 
o algoritmo termina, e o fecho convexo está pronto.

AUTOR: Lorenzo Guimarães Moulin
*/
#include <bits/stdc++.h>
#include <complex>
#include <vector>
#define x real()
#define y imag()
using namespace std;
typedef complex<int> point;
typedef vector<point> polygon; //vetor de pontos é um polígono

int cross (point a, point b){
    return a.x*b.y - a.y*b.x;
}

bool left(point a, point b, point c){
    return cross (b-a, c-a) > 0;
}

polygon jarvis(polygon &p){
    point leftmost(1e9, 1e9), endpoint, lastpoint; // um ponto no infinito
    polygon hull; //convex hull
    for (auto ponto: p){ // encontrando ponto mais à esquerda
        if (ponto.x < leftmost.x) leftmost = ponto;
    }
    hull.push_back(leftmost);
    lastpoint = leftmost;
    do {
        endpoint = p[0];
        for (int j = 0; j < p.size(); ++j){
            if ((endpoint == lastpoint) or left(lastpoint, endpoint, p[j]))
                endpoint = p[j];
        }
        lastpoint = endpoint;
        hull.push_back(lastpoint);
    } while (lastpoint != hull[0]);
    return hull;
}

int main(){
    int n;
    cin >> n;
    polygon p(n);
    for (int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        p[i] = point(a, b);
    }
    auto h = jarvis(p);
    for (auto ponto: h){
        cout << "(" << ponto.x << ", " << ponto.y << ") | ";
    }
    cout << '\n';
    return 0;
}