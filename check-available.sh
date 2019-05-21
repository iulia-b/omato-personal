
# this is o mato
url="https://www.residentadvisor.net/events/1221651"

#this is the one in june - still has tickets used for proof of concept
# url="https://www.residentadvisor.net/events/1231158"

filename="test.html"
notif="Buy those fuckin tickets"
send_mail="mail -s \"Buy the tickeeets\" iulia.cristina.bejan@gmail.com"

wasShown=0


while true
do
    curl $url -o test.html
    # result=$(pup '#tickets ul .onsale' < $filename)
    result=$(pup '#tickets ul li.onsale p:contains("release")' < $filename)

    if [[ ${#result} -ge 4 && $wasShown -eq 0 ]]; then
        echo 'tickets available'
        let wasShown=1
        osascript -e 'display alert "Buy the tickeeets"'
        # eval($send_mail)
    elif [ ${#result} -lt 1 ]; then
        date "+no tickets at %H:%M:%S"
        let wasShown=0
    fi

    sleep 45
done