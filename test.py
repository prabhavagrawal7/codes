from subsai import SubsAI
import os, tqdm


folder = "/Users/prabhavagrawal7/Downloads/system_design/"
# get all files from the folder
files = os.listdir(folder)
# get all files not ending with .srt extension
files = [file for file in files if file.endswith(".mp4")]

files.sort()
# create an instance of SubsAI
subsai = SubsAI()
# create a model with uses c++ whisper implementation
model = subsai.create_model("guillaumekln/faster-whisper", {"model_type": "base"})
# generate subtitles for all files in the folder

# for file in files: # remove this and add tqdm to show progress bar
for file in tqdm.tqdm(files):
    file = folder + file
    subs = subsai.transcribe(file, model)
    # remove older file extension and add .srt extension
    file = "".join(file.split(".")[:-1]) + ".srt"
    subs.save(file)
    print(f"Subtitles saved to {file}")
