<xml>
<proxy>
    <group>sources</group>
    <name>BinReader</name>
    <label>Bin Reader</label>
    <documentation>
        <brief>Read a binary file and output its contents to the console.</brief>
        <long>
       The Bin Reader reads bin (Binary File) files. The default file extension is .bin.
     </long>
    </documentation>
    <property>
        <name>FileName</name>
        <label>FileName</label>
        <documentation>
            <brief/>
            <long>
          This property specifies the file name for the Bin reader.
        </long>
        </documentation>
        <defaults/>
        <domains>
            <domain>
                <text> The value(s) must be a filename (or filenames).</text>
            </domain>
        </domains>
    </property>
    <ReaderFactory extensions="bin" file_description="Select compressed .bin file"/>
</proxy>

</xml>
