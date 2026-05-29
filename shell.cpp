//Guilherme Paes e Vinicius Avila


class Solution {
public:

    // sortArray: ordena o array usando Shellsort

    // começa com gaps grandes e vai reduzindo até gap=1.

    // Sequência de gaps usada: Ciura (2001) --> sugestão do Claude
    
    //   {1, 4, 10, 23, 57, 132, 301, 701}
    
    //   Segundo a ferramenta, é a melhor sequência conhecida para n <= 10^6. 
    
    // Complexidade:
    //   Tempo  — O(n^1.3) a O(n^1.5) na prática com Ciura;
    //            pior caso depende da sequência (com Ciura: ~O(n^(4/3)))
    //   Espaço — O(1) — totalmente in-place, sem array auxiliar
    
    
    vector<int> sortArray(vector<int>& nums) {
       
        int n = nums.size();

        // Sequência de gaps de Ciura — usamos apenas os menores que n
        // Os gaps maiores que n são ignorados
        
        vector<int> gaps = {701, 301, 132, 57, 23, 10, 4, 1};

        //  Loop externo: itera sobre cada gap da sequência 
        // Começamos do maior gap útil e terminamos em gap=1
        for (int gap : gaps) {

            // Gaps maiores que n não produzem comparações válidas
            if (gap >= n) continue;

            //  Loop do Insertion Sort com gap 
            // Para cada posição `i` a partir de `gap`,
            // inserimos nums[i] na posição correta dentro
            // da subsequência espaçada por `gap`
            for (int i = gap; i < n; i++) {

                // Elemento a ser inserido na posição correta
                int temp = nums[i];

                // `j` começa em `i` e recua de `gap` em `gap`
                // enquanto o elemento anterior (nums[j - gap])
                // for maior que `temp`
                
                int j = i;
                while (j >= gap && nums[j - gap] > temp) {
                    
                    // Desloca o elemento uma posição adiante (no espaçamento gap)
                    nums[j] = nums[j - gap];
                    j -= gap;
                }

                // Insere `temp` na posição correta encontrada
                nums[j] = temp;
            }
            // Após essa passagem, o array está "gap-ordenado":
            // qualquer subsequência de índices {k, k+gap, k+2*gap, ...}
            // está ordenada entre si.
        }

        // Quando gap=1, o Shellsort se comporta como Insertion Sort,
        // mas o array já está quase ordenado pelas passagens anteriores,
        // tornando essa última etapa muito rápida (quase O(n))
        
        return nums;
    }
};
