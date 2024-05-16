import tensorflow as tf

x1 = tf.random.uniform([32, 10, 100, 3], dtype=tf.float32)
x2 = tf.random.uniform([32, 10, 100, 3], dtype=tf.float32)

# Ahhoz, hogy (32, 10, 100, 100) legyen az eredmény kell az utolsó előtti
# dimenió szerint az összes váriáció
x1 = tf.expand_dims(x1, axis=-2)
x2 = tf.expand_dims(x2, axis=-3)
print((x1-x2)[0, 0, 0, 0])

# Kiszámítjuk a különbség vektor hosszát, az utolsó dimenzióban
x3 = tf.norm(x1-x2, ord='euclidean', axis=-1)
print(x3.shape)
