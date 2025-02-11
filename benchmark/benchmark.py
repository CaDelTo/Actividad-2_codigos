import os

languages = ["python", "java", "cpp", "javascript", "go"]
results_dir = "/app/results"
times = {}

# Leer tiempos de ejecución desde los archivos generados
for lang in languages:
    try:
        with open(f"{results_dir}/{lang}_time.txt", "r") as f:
            times[lang] = int(f.read().strip())
    except FileNotFoundError:
        times[lang] = "Error"

# Ordenar por tiempo de ejecución
sorted_times = sorted(times.items(), key=lambda x: x[1] if isinstance(x[1], int) else float("inf"))

# Mostrar tabla

print("=" * 40)
print(f"{'Language':<12} | {'Execution Time (ms)':>20}")
print("-" * 40)
for lang, time in sorted_times:
    print(f"{lang:<12} | {str(time):>20}")
print("=" * 40)
