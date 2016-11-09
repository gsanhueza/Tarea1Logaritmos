# Inicializador

start = 9;
finish = 15;
for i = start : finish
  rectangles(i - start + 1) = 2^i;
end

# --- START DATA --- #

# Tiempos Inserción Linear Split

lst(1) = 0.103387;
lst(2) = 0.166307;
lst(3) = 0.321261;
lst(4) = 0.848601;
lst(5) = 1.410179;
lst(6) = 2.861004;
lst(7) = 5.593964;

# Tiempos Inserción Greene Split

gst(1) = 0.082136;
gst(2) = 0.177814;
gst(3) = 0.419102;
gst(4) = 1.610996;
gst(5) = 1.404789;
gst(6) = 2.787653;
gst(7) = 5.467977;

# Porcentajes de llenado

percent_fill(1) = 61.9;
percent_fill(2) = 70.7;
percent_fill(3) = 63.0;
percent_fill(4) = 57.0;
percent_fill(5) = 55.5;
percent_fill(6) = 53.3;
percent_fill(7) = 54.4;

# Tiempos Búsqueda Linear Split (mseg)

linear_search_time(1) = 0.012;
linear_search_time(2) = 0.021;
linear_search_time(3) = 0.020;
linear_search_time(4) = 0.040;
linear_search_time(5) = 0.019;
linear_search_time(6) = 0.048;
linear_search_time(7) = 0.012;

# Tiempos Búsqueda Greene Split (mseg)

greene_search_time(1) = 0.009;
greene_search_time(2) = 0.020;
greene_search_time(3) = 0.027;
greene_search_time(4) = 0.037;
greene_search_time(5) = 0.008;
greene_search_time(6) = 0.010;
greene_search_time(7) = 0.008;

# --- END DATA --- #

# Plot para Inserción

figure(1);
hold on;
semilogx(rectangles, lst, "r");
semilogx(rectangles, gst, "b");
legend("Linear Split", "Greene Split");
grid on;
xlabel ("Num. Rectangulos (log)");
ylabel ("Tiempo (segs)");
title ("Linear y Greene Split - Nímero de Rectangulos vs Tiempo de insercion");
hold off;

# Plot para espacio y % de llenado

figure(2);
hold on;
semilogx(rectangles, percent_fill, "g");
grid on;
xlabel ("Numero de Rectangulos (log)");
ylabel ("Porcentaje de llenado del nodo");
title ("Numero de Rectangulos vs % de llenado de nodos");
hold off;

# Plot para búsqueda

figure(3);
hold on;
semilogx(rectangles/10, linear_search_time, "r");
semilogx(rectangles/10, greene_search_time, "b");
legend("Linear Split", "Greene Split");
grid on;
xlabel ("Numero de Rectangulos (log)");
ylabel ("Tiempo de búsqueda (mseg)");
title ("Linear y Greene Split - Numero de Rectangulos vs Tiempo de busqueda");
hold off;
