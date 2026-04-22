import os
import shutil

MUTATIONS = [
    ("if data[j] > data[j + 1]:", "if data[j] < data[j + 1]:"),
    ("if data[j] > data[j + 1]:", "if data[j] >= data[j + 1]:"),
    ("if data[j] > data[j + 1]:", "if data[j] <= data[j + 1]:"),
    ("if data[j] > data[j + 1]:", "if True:"),
    ("range(0, n - i - 1)", "range(0, n - i)"),
    ("range(0, n - i - 1)", "range(0, 0)"),
    ("data[j], data[j + 1] = data[j + 1], data[j]", "pass"),
    ("n = len(data)", "n = len(data) - 1"),
    ("n = len(data)", "n = 0"),
    ("return data", "return []"),
    ("if data[j] > data[j + 1]:", "if data[j] != data[j + 1]:"),
    ("for i in range(n):", "for i in range(1):"),
    ("data = list(arr)", "data = []"),
    ("data[j], data[j + 1] = data[j + 1], data[j]", "data[j] = data[j+1]"),
    ("data[j], data[j + 1] = data[j + 1], data[j]", "data[j+1] = data[j]"),
    ("range(n)", "range(n-1)"),
    ("if data[j] > data[j + 1]:", "if data[j] == data[j + 1]:"),
    ("j + 1", "j"),
    ("j + 1", "j - 1"),
    ("data[j]", "data[0]"),
    ("range(0, n - i - 1)", "range(1, n - i - 1)"),
    ("i", "0"),
    ("range(n)", "range(n // 2)"),
    ("data = list(arr)", "data = arr"),
    ("if data[j] > data[j + 1]:", "if data[j+1] > data[j]:"),
    ("data[j] > data[j + 1]", "data[j] > data[0]"),
    ("n - i - 1", "n - 1"),
    ("range(n)", "range(n + 1)"),
    ("data[j], data[j + 1]", "data[j], data[j]"),
    ("return data", "return arr[::-1]")
]

def generate():
    from TestowanieUrzadzenWbudowanychSemIMagisterka.P7.test_vectors_data import TEST_DATA
    
    # 1. Tworzenie wektorów (pliki tekstowe)
    v_folder = "wektory_testowe"
    if os.path.exists(v_folder): shutil.rmtree(v_folder)
    os.makedirs(v_folder)
    for i, (inp, exp) in enumerate(TEST_DATA):
        with open(f"{v_folder}/input_{i:02d}.txt", "w") as f: f.write(str(inp))
        with open(f"{v_folder}/output_{i:02d}.txt", "w") as f: f.write(str(exp))
    
    # 2. Tworzenie mutantów (pliki .py)
    m_folder = "mutants"
    if os.path.exists(m_folder): shutil.rmtree(m_folder)
    os.makedirs(m_folder)
    with open("sort_alg.py", "r") as f: original = f.read()
    
    print(f"{'Nazwa':<12} | {'Status'}")
    print("-" * 30)
    killed = 0
    for i, (old, new) in enumerate(MUTATIONS):
        mutant_code = original.replace(old, new, 1)
        name = f"mutant_{i:02d}.py"
        with open(f"{m_folder}/{name}", "w") as f: f.write(mutant_code)
        
        # Testowanie mutanta
        try:
            namespace = {}
            exec(mutant_code, namespace)
            func = namespace['bubble_sort']
            is_killed = False
            for inp, exp in TEST_DATA:
                if func(list(inp)) != exp:
                    is_killed = True
                    break
            status = "KILLED" if is_killed else "SURVIVED"
        except:
            status = "KILLED (Runtime Error)"
            
        if "KILLED" in status: killed += 1
        print(f"Mutant {i:02d}   | {status}")

    print("-" * 30)
    print(f"Wynik: {killed}/{len(MUTATIONS)} ({(killed/len(MUTATIONS))*100:.2f}%)")

if __name__ == "__main__":
    generate()