from sist2 import Sist2Index
import sys
import os

index = Sist2Index(sys.argv[1])

for doc in index.document_iter():
    # Extract the path between the second and third '/' characters
    path_parts = doc.path.split('/')
    if len(path_parts) > 2:
        tag = f"{path_parts[2]}.{path_parts[3].replace('.', '_')}.#00FF00"
        print(f"tag '{tag}'")
        doc.json_data["tag"] = [tag]
        index.update_document(doc)

index.sync_tag_table()
index.commit()
print("Done!")