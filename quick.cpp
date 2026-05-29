// Quicksort — O(n log n) médio, O(n²) pior caso, O(log n) espaço (pilha)
class Solution {
public:
    // Recursão principal: divide o array em torno do pivô e ordena cada metade
    
void sort(vector<int> &a, int low, int high) {
        if (low >= high) return;         // subarray de 0 ou 1 elemento já está ordenado

        int p = partition(a, low, high); // p é a posição FINAL do pivô
        sort(a, low, p - 1);             // ordena tudo à esquerda do pivô
        sort(a, p + 1, high);            // ordena tudo à direita do pivô
    }

    // Troca dois elementos de posição dentro do array
    inline void troca(vector<int> &a, int x, int y) {
        int t = a[x];
        a[x] = a[y];
        a[y] = t;
    }

    //   escolhe a[high] como pivô e rearranja o subarray [low..high] de forma que:
    //   - tudo em [low .. i]   <= pivô
    //   - tudo em [i+1 .. high-1] > pivô
    //   - a[i+1] == pivô (posição final)

    //   `i` é a fronteira do lado "menor ou igual"; avança só quando a[j] <= pivô.
    //   `j` varre todos os candidatos; a[high] (pivô) nunca entra no loop.
    
    inline int partition(vector<int> &a, int low, int high) {
        int pivot = a[high]; // pivô fixo: último elemento do subarray
        int i = low - 1;     // i aponta para o último elemento <= pivô encontrado até agora

        for (int j = low; j < high; j++) {
            if (a[j] <= pivot) {
                troca(a, ++i, j); // expande a região "<=pivoo" e coloca a[j] nela
            }
        }

        troca(a, i + 1, high);  // coloca o pivô entre as duas regiões
        return i + 1;           // retorna o índice final do pivô
    }

    vector<int> sortArray(vector<int>& nums) {
       
        
        sort(nums, 0, nums.size() - 1);
        return nums;
    }
};
