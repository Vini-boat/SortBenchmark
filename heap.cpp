class Solution {

public:
    
    // heapF: mantém a propriedade de Max-Heap na subárvore
    // cuja raiz está em `raiz`, num array de tamanho `n`.

    void heapF(vector<int>& nums, int n, int raiz) {
        
        int maior = raiz;       
        int esq    = 2 * raiz + 1;  // filho esquerdo (índice baseado em 0)
        int dir   = 2 * raiz + 2;  // filho direito

        // Se filho esquerdo existe e é maior que o maior atual
        
        if (esq < n && nums[esq] > nums[maior])
            maior = esq;

        // Se filho direito existe e é maior que o maior atual
        
        if (dir < n && nums[dir] > nums[maior])
            maior = dir;

        // Se a raiz não é o maior, troca e continua descendo
        
        if (maior != raiz) {
            swap(nums[raiz], nums[maior]);
            
            // Chamada recursiva na subárvore afetada
            
            heapF(nums, n, maior);
        }
    }

// sortArray: ordena o array usando Heapsort
    
// Fase 1 — Construir Max-Heap: O(n)
    //   Percorre de baixo pra cima a partir do último nó
    //   interno (índice n/2 - 1), chamando heapF em cada um.

// Fase 2 — Extrair elementos em ordem: O(n log n)
    //   A cada iteração:
    //     1. Coloca o maior (raiz) no final do array.
    //     2. Reduz o heap em 1.
    //     3. Restaura a propriedade de Max-Heap.
    //
    // Espaço total: O(1) — tudo in-place, sem array auxiliar.
    
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        // ── FASE 1: Construção do Max-Heap 
        
        // Último nó interno está em n/2 - 1.
        // Nós folha (de n/2 até n-1) já são heaps triviais (pois são folhas --> não tem filhos) e não precisamos verificar.
        
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapF(nums, n, i);
        }

        // ── FASE 2: Extração ordenada 
        
        // A raiz (nums[0]) é sempre o maior elemento do heap.
        // Colocamos ela na posição correta (final do range)
        // e restauramos o heap no range reduzido.
        
        for (int i = n - 1; i > 0; i--) {
            
            // Troca raiz (maior) com o último elemento do heap atual
            
            swap(nums[0], nums[i]);

            // Restaura Max-Heap no subarray nums[0..i-1]
            
            heapF(nums, i, 0);
        }

        return nums;  // array ordenado em ordem crescente
    }
};
