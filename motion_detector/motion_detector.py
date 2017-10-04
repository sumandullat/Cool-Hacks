import cv2,time,pandas
from datetime import datetime as dt

first_frame=None
status_list=[None,None]
times=[]
df=pandas.DataFrame(columns=["start","end"])
video=cv2.VideoCapture(0)

while True:
    check,frame=video.read()
    status=0
    gray_frame=cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
    gray_frame=cv2.GaussianBlur(gray_frame,(21,21),0)
    if first_frame is None:
        first_frame=gray_frame
        continue
    delta_frame=cv2.absdiff(first_frame,gray_frame)
    thresh_frame=cv2.threshold(delta_frame,30,255,cv2.THRESH_BINARY)[1]
    thresh_frame=cv2.dilate(thresh_frame,None,iterations=20)
    (_,cnts,_)=cv2.findContours(thresh_frame.copy(),cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)
    for c in cnts:
        if cv2.contourArea(c)<1000:
            continue
        status=1
        (x,y,w,h)=cv2.boundingRect(c)
        cv2.rectangle(frame,(x,y),(x+w,y+h),(0,255,0),3)
    status_list.append(status)
    status_list=status_list[-2:]
    if status_list[-1]==1 and status_list[-2]==0:
        times.append(dt.now())
    if status_list[-1]==0 and status_list[-2]==1:
        times.append(dt.now())

    cv2.imshow("gray",gray_frame)
    cv2.imshow("thresh",thresh_frame)
    cv2.imshow("delta",delta_frame)
    cv2.imshow("color",frame)

    key=cv2.waitKey(1)
    if key==ord('q'):
        if status==1:
            times.append(dt.now())
        break
print(status_list)
print(times)
for i in range(0,len(times),2):
    df=df.append({"start":times[i],"end":times[i+1]},ignore_index=True)

df.to_csv("times.csv")
video.release()
cv2.destroyAllWindows()
