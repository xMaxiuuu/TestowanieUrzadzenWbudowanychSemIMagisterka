BEGIN {
    print "<html><head><meta charset='UTF-8'></head><body>"
    print "<table border='1' style='border-collapse: collapse;'>"
    print "<tr><th>Adres PCI</th><th>Opis urządzenia</th><th>ID [Vendor:Device]</th></tr>"
}

{
    match($0, /\[[0-9a-fA-F]{4}:[0-9a-fA-F]{4}\]/)
    device_id = substr($0, RSTART, RLENGTH)

    description = substr($0, index($0, " ") + 1)
    sub(/\[[0-9a-fA-F]{4}:[0-9a-fA-F]{4}\].*/, "", description)

    print "<tr>"
    print "  <td>" $1 "</td>"
    print "  <td>" description "</td>"
    print "  <td>" device_id "</td>"
    print "</tr>"
}

END {
    print "</table></body></html>"
}