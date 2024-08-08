from sist2 import Sist2Index
import sys
import os
import re

index = Sist2Index(sys.argv[1])

for doc in index.document_iter():
    # Extract the path between the second and third '/' characters
    path_parts = doc.path.split('/')
    if len(path_parts) > 2:
        # Extract the tag from the path
        tag = f"{path_parts[2]}.{path_parts[3].replace('.', '_')}.#00FF00"

        # Extract the author from the document's JSON data
        author = None
        if 'author' in doc.json_data:
            author = doc.json_data['author']
        elif 'meta' in doc.json_data and 'author' in doc.json_data['meta']:
            author = doc.json_data['meta']['author']

        if author:
            # Extract the last name from the author
            author_parts = re.split(r',\s*', author)
            last_name = author_parts[0]

            # Create a tag for the author
            author_tag = f"author.{last_name.replace('.', ' ')}.#FF00FF"

            doc.json_data["tag"] = [tag, author_tag]
        else:

            doc.json_data["tag"] = [tag]

        index.update_document(doc)
        print(f"Tagging document '{tag}', '{author_tag}'")        

index.sync_tag_table()
index.commit()
print("Done!")