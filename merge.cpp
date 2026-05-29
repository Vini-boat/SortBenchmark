// MergeSort — O(n log n) garantido em todos os casos, O(n) espaço auxiliar
class Solution {
public:
    
    // Fase "divide": parte o subarray [low..high] ao meio recursivamente
    // até restar subarrays de 1 elemento (caso base: low >= high)
    
    void divide(vector<int> &a, vector<int> &aux, int low, int high) {
        if (low >= high) return;

        int middle = (low + high) / 2;       // ponto de corte — evita overflow vs (low+high)
        divide(a, aux, low, middle);          // desce na metade esquerda
        divide(a, aux, middle + 1, high);     // desce na metade direita
        conquer(a, aux, low, middle, high);   // mescla as duas metades já ordenadas
    }

    // Fase "conquer": mescla dois subarrays ordenados [low..middle] e [middle+1..high]
    // produzindo um único subarray ordenado em a[low..high]
    
    void conquer(vector<int> &a, vector<int> &aux, int low, int middle, int high) {
        
        // Copia o trecho atual para aux — aux é a "foto" imutável da rodada
        // sem isso, sobrescrever a[] corromperia os valores ainda não lidos
        
        for (int k = low; k <= high; k++) aux[k] = a[k];

        int i = low;        // cursor na metade esquerda  (aux[low..middle])
        int j = middle + 1; // cursor na metade direita   (aux[middle+1..high])

        for (int k = low; k <= high; k++) {
            if      (i > middle)       a[k] = aux[j++]; // esquerda esgotada: consome direita
            else if (j > high)         a[k] = aux[i++]; // direita esgotada:  consome esquerda
            else if (aux[j] < aux[i])  a[k] = aux[j++]; // direita menor: vai primeiro (estável se <=)
            else                       a[k] = aux[i++]; // esquerda menor ou igual: vai primeiro
        }
        
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> aux(n); // alocado uma única vez aqui e reaproveitado em todas as chamadas
        divide(nums, aux, 0, n - 1);
        return nums;
    }
};
