import base64
import struct

# Encoded base64 string
encoded_data = "CgAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAD/wAAAAAAAAAAAAAAAAAAAAAAAAAAAAAD/xmZmZmZmaP/GZmZmZmZoAAAAAAAAAAAAAAAAAAAAAP/AAAAAAAAAAAAAAAAAAAApQ"

# Decode base64 string
decoded_data = base64.b64decode(encoded_data)

num_points = len(decoded_data) // 8

# Interpret binary data as double values
points = []
for i in range(num_points):
    # Read a single double (64 bits) from the binary data
    point = struct.unpack("<d", decoded_data[i*8:(i+1)*8])[0]
    points.append(point)

# Print the coordinates
for i, point in enumerate(points):
    print("Point {}: {}".format(i, point))