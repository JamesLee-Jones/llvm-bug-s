import argparse
import glob
import json
import os
import subprocess
from pathlib import Path


def main():
  parser = argparse.ArgumentParser()
  parser.add_argument("bugs_path", type=Path)
  parser.add_argument("compilers_path", type=Path)
  args = parser.parse_args()

  result = {}
 
  for bug_trigger in glob.glob(str(args.bugs_path / '**' / 'trigger.sh'), recursive=True):
    bug_number = os.path.dirname(bug_trigger)
    print(f"{bug_number}:")
    
    result[bug_number] = {} 
    result[bug_number]["compiler_versions"] = []
    reproducable = False
    regression = False

    absolute_compilers_path = (args.compilers_path / '**' / 'bin').absolute()
    for index, compiler in enumerate(sorted(glob.glob(str(absolute_compilers_path)))):
      p = subprocess.run(f'CC={compiler}/clang CXX={compiler}/clang++ {bug_trigger}', shell=True)
      result[bug_number]["compiler_versions"].append({"compiler": compiler, "return_code": p.returncode})
      if not reproducable and p.returncode == 1:
        reproducable = True
        if index > 0:
          regression = True
        
      print(f"  {compiler}: {p.returncode}")
    
    result[bug_number]["reproducable"] = reproducable
    result[bug_number]["regression"] = regression

  with open('triggering_versions.json', 'w') as f:
    json.dump(result, f, indent=4)

if __name__ == '__main__':
  main()
