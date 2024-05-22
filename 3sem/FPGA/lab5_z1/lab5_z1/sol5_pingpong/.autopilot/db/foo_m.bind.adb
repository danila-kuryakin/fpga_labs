<?xml version="1.0" encoding="UTF-8" standalone="yes" ?>
<!DOCTYPE boost_serialization>
<boost_serialization signature="serialization::archive" version="17">
<syndb class_id="0" tracking_level="0" version="0">
	<userIPLatency>-1</userIPLatency>
	<userIPName></userIPName>
	<cdfg class_id="1" tracking_level="1" version="0" object_id="_0">
		<name>foo_m</name>
		<module_structure>Dataflow</module_structure>
		<ret_bitwidth>0</ret_bitwidth>
		<ports class_id="2" tracking_level="0" version="0">
			<count>4</count>
			<item_version>0</item_version>
			<item class_id="3" tracking_level="1" version="0" object_id="_1">
				<Value class_id="4" tracking_level="0" version="0">
					<Obj class_id="5" tracking_level="0" version="0">
						<type>1</type>
						<id>1</id>
						<name>data_in</name>
						<fileName></fileName>
						<fileDirectory></fileDirectory>
						<lineNumber>0</lineNumber>
						<contextFuncName></contextFuncName>
						<contextNormFuncName></contextNormFuncName>
						<inlineStackInfo class_id="6" tracking_level="0" version="0">
							<count>0</count>
							<item_version>0</item_version>
						</inlineStackInfo>
						<originalName></originalName>
						<rtlName></rtlName>
						<control></control>
						<opType></opType>
						<implIndex></implIndex>
						<coreName>RAM</coreName>
						<isStorage>0</isStorage>
						<storageDepth>0</storageDepth>
						<coreId>1031040613</coreId>
						<rtlModuleName></rtlModuleName>
					</Obj>
					<bitwidth>32</bitwidth>
				</Value>
				<direction>0</direction>
				<if_type>1</if_type>
				<array_size>16384</array_size>
				<bit_vecs class_id="7" tracking_level="0" version="0">
					<count>0</count>
					<item_version>0</item_version>
				</bit_vecs>
			</item>
			<item class_id_reference="3" object_id="_2">
				<Value>
					<Obj>
						<type>1</type>
						<id>2</id>
						<name>scale</name>
						<fileName></fileName>
						<fileDirectory></fileDirectory>
						<lineNumber>0</lineNumber>
						<contextFuncName></contextFuncName>
						<contextNormFuncName></contextNormFuncName>
						<inlineStackInfo>
							<count>0</count>
							<item_version>0</item_version>
						</inlineStackInfo>
						<originalName>scale</originalName>
						<rtlName></rtlName>
						<control></control>
						<opType></opType>
						<implIndex></implIndex>
						<coreName></coreName>
						<isStorage>0</isStorage>
						<storageDepth>0</storageDepth>
						<coreId>1953391988</coreId>
						<rtlModuleName></rtlModuleName>
					</Obj>
					<bitwidth>32</bitwidth>
				</Value>
				<direction>0</direction>
				<if_type>0</if_type>
				<array_size>0</array_size>
				<bit_vecs>
					<count>0</count>
					<item_version>0</item_version>
				</bit_vecs>
			</item>
			<item class_id_reference="3" object_id="_3">
				<Value>
					<Obj>
						<type>1</type>
						<id>3</id>
						<name>data_out1</name>
						<fileName></fileName>
						<fileDirectory></fileDirectory>
						<lineNumber>0</lineNumber>
						<contextFuncName></contextFuncName>
						<contextNormFuncName></contextNormFuncName>
						<inlineStackInfo>
							<count>0</count>
							<item_version>0</item_version>
						</inlineStackInfo>
						<originalName></originalName>
						<rtlName></rtlName>
						<control></control>
						<opType></opType>
						<implIndex></implIndex>
						<coreName>RAM</coreName>
						<isStorage>0</isStorage>
						<storageDepth>0</storageDepth>
						<coreId>1031040613</coreId>
						<rtlModuleName></rtlModuleName>
					</Obj>
					<bitwidth>32</bitwidth>
				</Value>
				<direction>1</direction>
				<if_type>1</if_type>
				<array_size>16384</array_size>
				<bit_vecs>
					<count>0</count>
					<item_version>0</item_version>
				</bit_vecs>
			</item>
			<item class_id_reference="3" object_id="_4">
				<Value>
					<Obj>
						<type>1</type>
						<id>4</id>
						<name>data_out2</name>
						<fileName></fileName>
						<fileDirectory></fileDirectory>
						<lineNumber>0</lineNumber>
						<contextFuncName></contextFuncName>
						<contextNormFuncName></contextNormFuncName>
						<inlineStackInfo>
							<count>0</count>
							<item_version>0</item_version>
						</inlineStackInfo>
						<originalName></originalName>
						<rtlName></rtlName>
						<control></control>
						<opType></opType>
						<implIndex></implIndex>
						<coreName>RAM</coreName>
						<isStorage>0</isStorage>
						<storageDepth>0</storageDepth>
						<coreId>1031040613</coreId>
						<rtlModuleName></rtlModuleName>
					</Obj>
					<bitwidth>32</bitwidth>
				</Value>
				<direction>1</direction>
				<if_type>1</if_type>
				<array_size>16384</array_size>
				<bit_vecs>
					<count>0</count>
					<item_version>0</item_version>
				</bit_vecs>
			</item>
		</ports>
		<nodes class_id="8" tracking_level="0" version="0">
			<count>9</count>
			<item_version>0</item_version>
			<item class_id="9" tracking_level="1" version="0" object_id="_5">
				<Value>
					<Obj>
						<type>0</type>
						<id>15</id>
						<name>scale_read</name>
						<fileName></fileName>
						<fileDirectory></fileDirectory>
						<lineNumber>0</lineNumber>
						<contextFuncName></contextFuncName>
						<contextNormFuncName></contextNormFuncName>
						<inlineStackInfo>
							<count>0</count>
							<item_version>0</item_version>
						</inlineStackInfo>
						<originalName>scale</originalName>
						<rtlName></rtlName>
						<control></control>
						<opType></opType>
						<implIndex></implIndex>
						<coreName></coreName>
						<isStorage>0</isStorage>
						<storageDepth>0</storageDepth>
						<coreId>7602281</coreId>
						<rtlModuleName></rtlModuleName>
					</Obj>
					<bitwidth>32</bitwidth>
				</Value>
				<oprand_edges>
					<count>2</count>
					<item_version>0</item_version>
					<item>26</item>
					<item>27</item>
				</oprand_edges>
				<opcode>read</opcode>
				<m_Display>0</m_Display>
				<m_isOnCriticalPath>0</m_isOnCriticalPath>
				<m_isLCDNode>0</m_isLCDNode>
				<m_isStartOfPath>0</m_isStartOfPath>
				<m_delay>0.00</m_delay>
				<m_topoIndex>1</m_topoIndex>
				<m_clusterGroupNumber>-1</m_clusterGroupNumber>
			</item>
			<item class_id_reference="9" object_id="_6">
				<Value>
					<Obj>
						<type>0</type>
						<id>16</id>
						<name>temp1</name>
						<fileName>./source/lab5_z1.c</fileName>
						<fileDirectory>D:\Labs\3sem\FPGA\lab5_z1</fileDirectory>
						<lineNumber>18</lineNumber>
						<contextFuncName>foo_m</contextFuncName>
						<contextNormFuncName>foo_m</contextNormFuncName>
						<inlineStackInfo>
							<count>1</count>
							<item_version>0</item_version>
							<item class_id="11" tracking_level="0" version="0">
								<first>D:\Labs\3sem\FPGA\lab5_z1</first>
								<second class_id="12" tracking_level="0" version="0">
									<count>1</count>
									<item_version>0</item_version>
									<item class_id="13" tracking_level="0" version="0">
										<first class_id="14" tracking_level="0" version="0">
											<first>./source/lab5_z1.c</first>
											<second>foo_m</second>
										</first>
										<second>18</second>
									</item>
								</second>
							</item>
						</inlineStackInfo>
						<originalName>temp1</originalName>
						<rtlName></rtlName>
						<control>auto</control>
						<opType>ram</opType>
						<implIndex>auto</implIndex>
						<coreName>RAM</coreName>
						<isStorage>0</isStorage>
						<storageDepth>0</storageDepth>
						<coreId>82</coreId>
						<rtlModuleName></rtlModuleName>
					</Obj>
					<bitwidth>32</bitwidth>
				</Value>
				<oprand_edges>
					<count>1</count>
					<item_version>0</item_version>
					<item>29</item>
				</oprand_edges>
				<opcode>alloca</opcode>
				<m_Display>0</m_Display>
				<m_isOnCriticalPath>0</m_isOnCriticalPath>
				<m_isLCDNode>0</m_isLCDNode>
				<m_isStartOfPath>0</m_isStartOfPath>
				<m_delay>0.00</m_delay>
				<m_topoIndex>2</m_topoIndex>
				<m_clusterGroupNumber>-1</m_clusterGroupNumber>
			</item>
			<item class_id_reference="9" object_id="_7">
				<Value>
					<Obj>
						<type>0</type>
						<id>17</id>
						<name>temp2</name>
						<fileName>./source/lab5_z1.c</fileName>
						<fileDirectory>D:\Labs\3sem\FPGA\lab5_z1</fileDirectory>
						<lineNumber>18</lineNumber>
						<contextFuncName>foo_m</contextFuncName>
						<contextNormFuncName>foo_m</contextNormFuncName>
						<inlineStackInfo>
							<count>1</count>
							<item_version>0</item_version>
							<item>
								<first>D:\Labs\3sem\FPGA\lab5_z1</first>
								<second>
									<count>1</count>
									<item_version>0</item_version>
									<item>
										<first>
											<first>./source/lab5_z1.c</first>
											<second>foo_m</second>
										</first>
										<second>18</second>
									</item>
								</second>
							</item>
						</inlineStackInfo>
						<originalName>temp2</originalName>
						<rtlName></rtlName>
						<control>auto</control>
						<opType>ram</opType>
						<implIndex>auto</implIndex>
						<coreName>RAM</coreName>
						<isStorage>0</isStorage>
						<storageDepth>0</storageDepth>
						<coreId>82</coreId>
						<rtlModuleName></rtlModuleName>
					</Obj>
					<bitwidth>32</bitwidth>
				</Value>
				<oprand_edges>
					<count>1</count>
					<item_version>0</item_version>
					<item>30</item>
				</oprand_edges>
				<opcode>alloca</opcode>
				<m_Display>0</m_Display>
				<m_isOnCriticalPath>0</m_isOnCriticalPath>
				<m_isLCDNode>0</m_isLCDNode>
				<m_isStartOfPath>0</m_isStartOfPath>
				<m_delay>0.00</m_delay>
				<m_topoIndex>3</m_topoIndex>
				<m_clusterGroupNumber>-1</m_clusterGroupNumber>
			</item>
			<item class_id_reference="9" object_id="_8">
				<Value>
					<Obj>
						<type>0</type>
						<id>18</id>
						<name>temp3</name>
						<fileName>./source/lab5_z1.c</fileName>
						<fileDirectory>D:\Labs\3sem\FPGA\lab5_z1</fileDirectory>
						<lineNumber>18</lineNumber>
						<contextFuncName>foo_m</contextFuncName>
						<contextNormFuncName>foo_m</contextNormFuncName>
						<inlineStackInfo>
							<count>1</count>
							<item_version>0</item_version>
							<item>
								<first>D:\Labs\3sem\FPGA\lab5_z1</first>
								<second>
									<count>1</count>
									<item_version>0</item_version>
									<item>
										<first>
											<first>./source/lab5_z1.c</first>
											<second>foo_m</second>
										</first>
										<second>18</second>
									</item>
								</second>
							</item>
						</inlineStackInfo>
						<originalName>temp3</originalName>
						<rtlName></rtlName>
						<control>auto</control>
						<opType>ram</opType>
						<implIndex>auto</implIndex>
						<coreName>RAM</coreName>
						<isStorage>0</isStorage>
						<storageDepth>0</storageDepth>
						<coreId>82</coreId>
						<rtlModuleName></rtlModuleName>
					</Obj>
					<bitwidth>32</bitwidth>
				</Value>
				<oprand_edges>
					<count>1</count>
					<item_version>0</item_version>
					<item>31</item>
				</oprand_edges>
				<opcode>alloca</opcode>
				<m_Display>0</m_Display>
				<m_isOnCriticalPath>0</m_isOnCriticalPath>
				<m_isLCDNode>0</m_isLCDNode>
				<m_isStartOfPath>0</m_isStartOfPath>
				<m_delay>0.00</m_delay>
				<m_topoIndex>4</m_topoIndex>
				<m_clusterGroupNumber>-1</m_clusterGroupNumber>
			</item>
			<item class_id_reference="9" object_id="_9">
				<Value>
					<Obj>
						<type>0</type>
						<id>19</id>
						<name>_ln0</name>
						<fileName></fileName>
						<fileDirectory></fileDirectory>
						<lineNumber>0</lineNumber>
						<contextFuncName></contextFuncName>
						<contextNormFuncName></contextNormFuncName>
						<inlineStackInfo>
							<count>0</count>
							<item_version>0</item_version>
						</inlineStackInfo>
						<originalName></originalName>
						<rtlName></rtlName>
						<control></control>
						<opType></opType>
						<implIndex></implIndex>
						<coreName></coreName>
						<isStorage>0</isStorage>
						<storageDepth>0</storageDepth>
						<coreId>3276847</coreId>
						<rtlModuleName></rtlModuleName>
					</Obj>
					<bitwidth>0</bitwidth>
				</Value>
				<oprand_edges>
					<count>4</count>
					<item_version>0</item_version>
					<item>33</item>
					<item>34</item>
					<item>35</item>
					<item>36</item>
				</oprand_edges>
				<opcode>call</opcode>
				<m_Display>0</m_Display>
				<m_isOnCriticalPath>0</m_isOnCriticalPath>
				<m_isLCDNode>0</m_isLCDNode>
				<m_isStartOfPath>0</m_isStartOfPath>
				<m_delay>0.00</m_delay>
				<m_topoIndex>5</m_topoIndex>
				<m_clusterGroupNumber>-1</m_clusterGroupNumber>
			</item>
			<item class_id_reference="9" object_id="_10">
				<Value>
					<Obj>
						<type>0</type>
						<id>20</id>
						<name>_ln28</name>
						<fileName>./source/lab5_z1.c</fileName>
						<fileDirectory>D:\Labs\3sem\FPGA\lab5_z1</fileDirectory>
						<lineNumber>28</lineNumber>
						<contextFuncName>foo_m</contextFuncName>
						<contextNormFuncName>foo_m</contextNormFuncName>
						<inlineStackInfo>
							<count>1</count>
							<item_version>0</item_version>
							<item>
								<first>D:\Labs\3sem\FPGA\lab5_z1</first>
								<second>
									<count>1</count>
									<item_version>0</item_version>
									<item>
										<first>
											<first>./source/lab5_z1.c</first>
											<second>foo_m</second>
										</first>
										<second>28</second>
									</item>
								</second>
							</item>
						</inlineStackInfo>
						<originalName></originalName>
						<rtlName></rtlName>
						<control></control>
						<opType></opType>
						<implIndex></implIndex>
						<coreName></coreName>
						<isStorage>0</isStorage>
						<storageDepth>0</storageDepth>
						<coreId>49</coreId>
						<rtlModuleName></rtlModuleName>
					</Obj>
					<bitwidth>0</bitwidth>
				</Value>
				<oprand_edges>
					<count>6</count>
					<item_version>0</item_version>
					<item>38</item>
					<item>39</item>
					<item>40</item>
					<item>41</item>
					<item>144</item>
					<item>145</item>
				</oprand_edges>
				<opcode>call</opcode>
				<m_Display>0</m_Display>
				<m_isOnCriticalPath>0</m_isOnCriticalPath>
				<m_isLCDNode>0</m_isLCDNode>
				<m_isStartOfPath>0</m_isStartOfPath>
				<m_delay>0.00</m_delay>
				<m_topoIndex>6</m_topoIndex>
				<m_clusterGroupNumber>-1</m_clusterGroupNumber>
			</item>
			<item class_id_reference="9" object_id="_11">
				<Value>
					<Obj>
						<type>0</type>
						<id>21</id>
						<name>_ln0</name>
						<fileName></fileName>
						<fileDirectory></fileDirectory>
						<lineNumber>0</lineNumber>
						<contextFuncName></contextFuncName>
						<contextNormFuncName></contextNormFuncName>
						<inlineStackInfo>
							<count>0</count>
							<item_version>0</item_version>
						</inlineStackInfo>
						<originalName></originalName>
						<rtlName></rtlName>
						<control></control>
						<opType></opType>
						<implIndex></implIndex>
						<coreName></coreName>
						<isStorage>0</isStorage>
						<storageDepth>0</storageDepth>
						<coreId>7864430</coreId>
						<rtlModuleName></rtlModuleName>
					</Obj>
					<bitwidth>0</bitwidth>
				</Value>
				<oprand_edges>
					<count>5</count>
					<item_version>0</item_version>
					<item>43</item>
					<item>44</item>
					<item>45</item>
					<item>142</item>
					<item>146</item>
				</oprand_edges>
				<opcode>call</opcode>
				<m_Display>0</m_Display>
				<m_isOnCriticalPath>0</m_isOnCriticalPath>
				<m_isLCDNode>0</m_isLCDNode>
				<m_isStartOfPath>0</m_isStartOfPath>
				<m_delay>0.00</m_delay>
				<m_topoIndex>7</m_topoIndex>
				<m_clusterGroupNumber>-1</m_clusterGroupNumber>
			</item>
			<item class_id_reference="9" object_id="_12">
				<Value>
					<Obj>
						<type>0</type>
						<id>22</id>
						<name>_ln0</name>
						<fileName></fileName>
						<fileDirectory></fileDirectory>
						<lineNumber>0</lineNumber>
						<contextFuncName></contextFuncName>
						<contextNormFuncName></contextNormFuncName>
						<inlineStackInfo>
							<count>0</count>
							<item_version>0</item_version>
						</inlineStackInfo>
						<originalName></originalName>
						<rtlName></rtlName>
						<control></control>
						<opType></opType>
						<implIndex></implIndex>
						<coreName></coreName>
						<isStorage>0</isStorage>
						<storageDepth>0</storageDepth>
						<coreId>6881368</coreId>
						<rtlModuleName></rtlModuleName>
					</Obj>
					<bitwidth>0</bitwidth>
				</Value>
				<oprand_edges>
					<count>4</count>
					<item_version>0</item_version>
					<item>47</item>
					<item>48</item>
					<item>49</item>
					<item>143</item>
				</oprand_edges>
				<opcode>call</opcode>
				<m_Display>0</m_Display>
				<m_isOnCriticalPath>0</m_isOnCriticalPath>
				<m_isLCDNode>0</m_isLCDNode>
				<m_isStartOfPath>0</m_isStartOfPath>
				<m_delay>0.00</m_delay>
				<m_topoIndex>8</m_topoIndex>
				<m_clusterGroupNumber>-1</m_clusterGroupNumber>
			</item>
			<item class_id_reference="9" object_id="_13">
				<Value>
					<Obj>
						<type>0</type>
						<id>23</id>
						<name>_ln45</name>
						<fileName>./source/lab5_z1.c</fileName>
						<fileDirectory>D:\Labs\3sem\FPGA\lab5_z1</fileDirectory>
						<lineNumber>45</lineNumber>
						<contextFuncName>foo_m</contextFuncName>
						<contextNormFuncName>foo_m</contextNormFuncName>
						<inlineStackInfo>
							<count>1</count>
							<item_version>0</item_version>
							<item>
								<first>D:\Labs\3sem\FPGA\lab5_z1</first>
								<second>
									<count>1</count>
									<item_version>0</item_version>
									<item>
										<first>
											<first>./source/lab5_z1.c</first>
											<second>foo_m</second>
										</first>
										<second>45</second>
									</item>
								</second>
							</item>
						</inlineStackInfo>
						<originalName></originalName>
						<rtlName></rtlName>
						<control></control>
						<opType></opType>
						<implIndex></implIndex>
						<coreName></coreName>
						<isStorage>0</isStorage>
						<storageDepth>0</storageDepth>
						<coreId>6881396</coreId>
						<rtlModuleName></rtlModuleName>
					</Obj>
					<bitwidth>0</bitwidth>
				</Value>
				<oprand_edges>
					<count>0</count>
					<item_version>0</item_version>
				</oprand_edges>
				<opcode>ret</opcode>
				<m_Display>0</m_Display>
				<m_isOnCriticalPath>0</m_isOnCriticalPath>
				<m_isLCDNode>0</m_isLCDNode>
				<m_isStartOfPath>0</m_isStartOfPath>
				<m_delay>0.00</m_delay>
				<m_topoIndex>9</m_topoIndex>
				<m_clusterGroupNumber>-1</m_clusterGroupNumber>
			</item>
		</nodes>
		<consts class_id="15" tracking_level="0" version="0">
			<count>5</count>
			<item_version>0</item_version>
			<item class_id="16" tracking_level="1" version="0" object_id="_14">
				<Value>
					<Obj>
						<type>2</type>
						<id>28</id>
						<name>empty</name>
						<fileName></fileName>
						<fileDirectory></fileDirectory>
						<lineNumber>0</lineNumber>
						<contextFuncName></contextFuncName>
						<contextNormFuncName></contextNormFuncName>
						<inlineStackInfo>
							<count>0</count>
							<item_version>0</item_version>
						</inlineStackInfo>
						<originalName></originalName>
						<rtlName></rtlName>
						<control></control>
						<opType></opType>
						<implIndex></implIndex>
						<coreName></coreName>
						<isStorage>0</isStorage>
						<storageDepth>0</storageDepth>
						<coreId>1031040613</coreId>
						<rtlModuleName></rtlModuleName>
					</Obj>
					<bitwidth>64</bitwidth>
				</Value>
				<const_type>0</const_type>
				<content>1</content>
			</item>
			<item class_id_reference="16" object_id="_15">
				<Value>
					<Obj>
						<type>2</type>
						<id>32</id>
						<name>Loop_Loop1_proc</name>
						<fileName></fileName>
						<fileDirectory></fileDirectory>
						<lineNumber>0</lineNumber>
						<contextFuncName></contextFuncName>
						<contextNormFuncName></contextNormFuncName>
						<inlineStackInfo>
							<count>0</count>
							<item_version>0</item_version>
						</inlineStackInfo>
						<originalName></originalName>
						<rtlName></rtlName>
						<control></control>
						<opType></opType>
						<implIndex></implIndex>
						<coreName></coreName>
						<isStorage>0</isStorage>
						<storageDepth>0</storageDepth>
						<coreId>1698970656</coreId>
						<rtlModuleName></rtlModuleName>
					</Obj>
					<bitwidth>0</bitwidth>
				</Value>
				<const_type>6</const_type>
				<content>&lt;constant:Loop_Loop1_proc&gt;</content>
			</item>
			<item class_id_reference="16" object_id="_16">
				<Value>
					<Obj>
						<type>2</type>
						<id>37</id>
						<name>split</name>
						<fileName></fileName>
						<fileDirectory></fileDirectory>
						<lineNumber>0</lineNumber>
						<contextFuncName></contextFuncName>
						<contextNormFuncName></contextNormFuncName>
						<inlineStackInfo>
							<count>0</count>
							<item_version>0</item_version>
						</inlineStackInfo>
						<originalName></originalName>
						<rtlName></rtlName>
						<control></control>
						<opType></opType>
						<implIndex></implIndex>
						<coreName></coreName>
						<isStorage>0</isStorage>
						<storageDepth>0</storageDepth>
						<coreId>4016480464</coreId>
						<rtlModuleName></rtlModuleName>
					</Obj>
					<bitwidth>0</bitwidth>
				</Value>
				<const_type>6</const_type>
				<content>&lt;constant:split&gt;</content>
			</item>
			<item class_id_reference="16" object_id="_17">
				<Value>
					<Obj>
						<type>2</type>
						<id>42</id>
						<name>Loop_Loop2_proc</name>
						<fileName></fileName>
						<fileDirectory></fileDirectory>
						<lineNumber>0</lineNumber>
						<contextFuncName></contextFuncName>
						<contextNormFuncName></contextNormFuncName>
						<inlineStackInfo>
							<count>0</count>
							<item_version>0</item_version>
						</inlineStackInfo>
						<originalName></originalName>
						<rtlName></rtlName>
						<control></control>
						<opType></opType>
						<implIndex></implIndex>
						<coreName></coreName>
						<isStorage>0</isStorage>
						<storageDepth>0</storageDepth>
						<coreId>1953391988</coreId>
						<rtlModuleName></rtlModuleName>
					</Obj>
					<bitwidth>0</bitwidth>
				</Value>
				<const_type>6</const_type>
				<content>&lt;constant:Loop_Loop2_proc&gt;</content>
			</item>
			<item class_id_reference="16" object_id="_18">
				<Value>
					<Obj>
						<type>2</type>
						<id>46</id>
						<name>Loop_Loop3_proc</name>
						<fileName></fileName>
						<fileDirectory></fileDirectory>
						<lineNumber>0</lineNumber>
						<contextFuncName></contextFuncName>
						<contextNormFuncName></contextNormFuncName>
						<inlineStackInfo>
							<count>0</count>
							<item_version>0</item_version>
						</inlineStackInfo>
						<originalName></originalName>
						<rtlName></rtlName>
						<control></control>
						<opType></opType>
						<implIndex></implIndex>
						<coreName></coreName>
						<isStorage>0</isStorage>
						<storageDepth>0</storageDepth>
						<coreId>1953391988</coreId>
						<rtlModuleName></rtlModuleName>
					</Obj>
					<bitwidth>0</bitwidth>
				</Value>
				<const_type>6</const_type>
				<content>&lt;constant:Loop_Loop3_proc&gt;</content>
			</item>
		</consts>
		<blocks class_id="17" tracking_level="0" version="0">
			<count>1</count>
			<item_version>0</item_version>
			<item class_id="18" tracking_level="1" version="0" object_id="_19">
				<Obj>
					<type>3</type>
					<id>24</id>
					<name>foo_m</name>
					<fileName></fileName>
					<fileDirectory></fileDirectory>
					<lineNumber>0</lineNumber>
					<contextFuncName></contextFuncName>
					<contextNormFuncName></contextNormFuncName>
					<inlineStackInfo>
						<count>0</count>
						<item_version>0</item_version>
					</inlineStackInfo>
					<originalName></originalName>
					<rtlName></rtlName>
					<control></control>
					<opType></opType>
					<implIndex></implIndex>
					<coreName></coreName>
					<isStorage>0</isStorage>
					<storageDepth>0</storageDepth>
					<coreId>4294967295</coreId>
					<rtlModuleName></rtlModuleName>
				</Obj>
				<node_objs>
					<count>9</count>
					<item_version>0</item_version>
					<item>15</item>
					<item>16</item>
					<item>17</item>
					<item>18</item>
					<item>19</item>
					<item>20</item>
					<item>21</item>
					<item>22</item>
					<item>23</item>
				</node_objs>
			</item>
		</blocks>
		<edges class_id="19" tracking_level="0" version="0">
			<count>23</count>
			<item_version>0</item_version>
			<item class_id="20" tracking_level="1" version="0" object_id="_20">
				<id>27</id>
				<edge_type>1</edge_type>
				<source_obj>2</source_obj>
				<sink_obj>15</sink_obj>
				<is_back_edge>0</is_back_edge>
			</item>
			<item class_id_reference="20" object_id="_21">
				<id>29</id>
				<edge_type>1</edge_type>
				<source_obj>28</source_obj>
				<sink_obj>16</sink_obj>
				<is_back_edge>0</is_back_edge>
			</item>
			<item class_id_reference="20" object_id="_22">
				<id>30</id>
				<edge_type>1</edge_type>
				<source_obj>28</source_obj>
				<sink_obj>17</sink_obj>
				<is_back_edge>0</is_back_edge>
			</item>
			<item class_id_reference="20" object_id="_23">
				<id>31</id>
				<edge_type>1</edge_type>
				<source_obj>28</source_obj>
				<sink_obj>18</sink_obj>
				<is_back_edge>0</is_back_edge>
			</item>
			<item class_id_reference="20" object_id="_24">
				<id>33</id>
				<edge_type>1</edge_type>
				<source_obj>32</source_obj>
				<sink_obj>19</sink_obj>
				<is_back_edge>0</is_back_edge>
			</item>
			<item class_id_reference="20" object_id="_25">
				<id>34</id>
				<edge_type>1</edge_type>
				<source_obj>1</source_obj>
				<sink_obj>19</sink_obj>
				<is_back_edge>0</is_back_edge>
			</item>
			<item class_id_reference="20" object_id="_26">
				<id>35</id>
				<edge_type>1</edge_type>
				<source_obj>15</source_obj>
				<sink_obj>19</sink_obj>
				<is_back_edge>0</is_back_edge>
			</item>
			<item class_id_reference="20" object_id="_27">
				<id>36</id>
				<edge_type>1</edge_type>
				<source_obj>16</source_obj>
				<sink_obj>19</sink_obj>
				<is_back_edge>0</is_back_edge>
			</item>
			<item class_id_reference="20" object_id="_28">
				<id>38</id>
				<edge_type>1</edge_type>
				<source_obj>37</source_obj>
				<sink_obj>20</sink_obj>
				<is_back_edge>0</is_back_edge>
			</item>
			<item class_id_reference="20" object_id="_29">
				<id>39</id>
				<edge_type>1</edge_type>
				<source_obj>16</source_obj>
				<sink_obj>20</sink_obj>
				<is_back_edge>0</is_back_edge>
			</item>
			<item class_id_reference="20" object_id="_30">
				<id>40</id>
				<edge_type>1</edge_type>
				<source_obj>17</source_obj>
				<sink_obj>20</sink_obj>
				<is_back_edge>0</is_back_edge>
			</item>
			<item class_id_reference="20" object_id="_31">
				<id>41</id>
				<edge_type>1</edge_type>
				<source_obj>18</source_obj>
				<sink_obj>20</sink_obj>
				<is_back_edge>0</is_back_edge>
			</item>
			<item class_id_reference="20" object_id="_32">
				<id>43</id>
				<edge_type>1</edge_type>
				<source_obj>42</source_obj>
				<sink_obj>21</sink_obj>
				<is_back_edge>0</is_back_edge>
			</item>
			<item class_id_reference="20" object_id="_33">
				<id>44</id>
				<edge_type>1</edge_type>
				<source_obj>17</source_obj>
				<sink_obj>21</sink_obj>
				<is_back_edge>0</is_back_edge>
			</item>
			<item class_id_reference="20" object_id="_34">
				<id>45</id>
				<edge_type>1</edge_type>
				<source_obj>3</source_obj>
				<sink_obj>21</sink_obj>
				<is_back_edge>0</is_back_edge>
			</item>
			<item class_id_reference="20" object_id="_35">
				<id>47</id>
				<edge_type>1</edge_type>
				<source_obj>46</source_obj>
				<sink_obj>22</sink_obj>
				<is_back_edge>0</is_back_edge>
			</item>
			<item class_id_reference="20" object_id="_36">
				<id>48</id>
				<edge_type>1</edge_type>
				<source_obj>18</source_obj>
				<sink_obj>22</sink_obj>
				<is_back_edge>0</is_back_edge>
			</item>
			<item class_id_reference="20" object_id="_37">
				<id>49</id>
				<edge_type>1</edge_type>
				<source_obj>4</source_obj>
				<sink_obj>22</sink_obj>
				<is_back_edge>0</is_back_edge>
			</item>
			<item class_id_reference="20" object_id="_38">
				<id>142</id>
				<edge_type>4</edge_type>
				<source_obj>20</source_obj>
				<sink_obj>21</sink_obj>
				<is_back_edge>0</is_back_edge>
			</item>
			<item class_id_reference="20" object_id="_39">
				<id>143</id>
				<edge_type>4</edge_type>
				<source_obj>20</source_obj>
				<sink_obj>22</sink_obj>
				<is_back_edge>0</is_back_edge>
			</item>
			<item class_id_reference="20" object_id="_40">
				<id>144</id>
				<edge_type>4</edge_type>
				<source_obj>19</source_obj>
				<sink_obj>20</sink_obj>
				<is_back_edge>0</is_back_edge>
			</item>
			<item class_id_reference="20" object_id="_41">
				<id>145</id>
				<edge_type>4</edge_type>
				<source_obj>19</source_obj>
				<sink_obj>20</sink_obj>
				<is_back_edge>0</is_back_edge>
			</item>
			<item class_id_reference="20" object_id="_42">
				<id>146</id>
				<edge_type>4</edge_type>
				<source_obj>20</source_obj>
				<sink_obj>21</sink_obj>
				<is_back_edge>0</is_back_edge>
			</item>
		</edges>
	</cdfg>
	<cdfg_regions class_id="21" tracking_level="0" version="0">
		<count>1</count>
		<item_version>0</item_version>
		<item class_id="22" tracking_level="1" version="0" object_id="_43">
			<mId>1</mId>
			<mTag>foo_m</mTag>
			<mNormTag>foo_m</mNormTag>
			<mType>0</mType>
			<sub_regions>
				<count>0</count>
				<item_version>0</item_version>
			</sub_regions>
			<basic_blocks>
				<count>1</count>
				<item_version>0</item_version>
				<item>24</item>
			</basic_blocks>
			<mII>-1</mII>
			<mDepth>-1</mDepth>
			<mMinTripCount>-1</mMinTripCount>
			<mMaxTripCount>-1</mMaxTripCount>
			<mMinLatency>163845</mMinLatency>
			<mMaxLatency>163845</mMaxLatency>
			<mIsDfPipe>1</mIsDfPipe>
			<mDfPipe class_id="23" tracking_level="1" version="0" object_id="_44">
				<port_list class_id="24" tracking_level="0" version="0">
					<count>4</count>
					<item_version>0</item_version>
					<item class_id="25" tracking_level="1" version="0" object_id="_45">
						<name>data_in</name>
						<dir>0</dir>
						<type>2</type>
						<need_hs>1</need_hs>
						<top_port class_id="-1"></top_port>
						<chan class_id="-1"></chan>
					</item>
					<item class_id_reference="25" object_id="_46">
						<name>scale</name>
						<dir>0</dir>
						<type>3</type>
						<need_hs>1</need_hs>
						<top_port class_id="-1"></top_port>
						<chan class_id="-1"></chan>
					</item>
					<item class_id_reference="25" object_id="_47">
						<name>data_out1</name>
						<dir>1</dir>
						<type>2</type>
						<need_hs>0</need_hs>
						<top_port class_id="-1"></top_port>
						<chan class_id="-1"></chan>
					</item>
					<item class_id_reference="25" object_id="_48">
						<name>data_out2</name>
						<dir>1</dir>
						<type>2</type>
						<need_hs>0</need_hs>
						<top_port class_id="-1"></top_port>
						<chan class_id="-1"></chan>
					</item>
				</port_list>
				<process_list class_id="27" tracking_level="0" version="0">
					<count>4</count>
					<item_version>0</item_version>
					<item class_id="28" tracking_level="1" version="0" object_id="_49">
						<type>0</type>
						<name>Loop_Loop1_proc_U0</name>
						<ssdmobj_id>19</ssdmobj_id>
						<pins class_id="29" tracking_level="0" version="0">
							<count>2</count>
							<item_version>0</item_version>
							<item class_id="30" tracking_level="1" version="0" object_id="_50">
								<port class_id_reference="25" object_id="_51">
									<name>data_in</name>
									<dir>0</dir>
									<type>2</type>
									<need_hs>1</need_hs>
									<top_port class_id_reference="25" object_id_reference="_45"></top_port>
									<chan class_id="-1"></chan>
								</port>
								<inst class_id="31" tracking_level="1" version="0" object_id="_52">
									<type>0</type>
									<name>Loop_Loop1_proc_U0</name>
									<ssdmobj_id>19</ssdmobj_id>
								</inst>
							</item>
							<item class_id_reference="30" object_id="_53">
								<port class_id_reference="25" object_id="_54">
									<name>scale</name>
									<dir>0</dir>
									<type>3</type>
									<need_hs>1</need_hs>
									<top_port class_id_reference="25" object_id_reference="_46"></top_port>
									<chan class_id="-1"></chan>
								</port>
								<inst class_id_reference="31" object_id_reference="_52"></inst>
							</item>
						</pins>
						<in_source_fork>1</in_source_fork>
						<in_sink_join>0</in_sink_join>
						<flag_in_gui>0</flag_in_gui>
					</item>
					<item class_id_reference="28" object_id="_55">
						<type>0</type>
						<name>split_U0</name>
						<ssdmobj_id>20</ssdmobj_id>
						<pins>
							<count>0</count>
							<item_version>0</item_version>
						</pins>
						<in_source_fork>0</in_source_fork>
						<in_sink_join>0</in_sink_join>
						<flag_in_gui>0</flag_in_gui>
					</item>
					<item class_id_reference="28" object_id="_56">
						<type>0</type>
						<name>Loop_Loop2_proc_U0</name>
						<ssdmobj_id>21</ssdmobj_id>
						<pins>
							<count>1</count>
							<item_version>0</item_version>
							<item class_id_reference="30" object_id="_57">
								<port class_id_reference="25" object_id="_58">
									<name>data_out1</name>
									<dir>1</dir>
									<type>2</type>
									<need_hs>1</need_hs>
									<top_port class_id_reference="25" object_id_reference="_47"></top_port>
									<chan class_id="-1"></chan>
								</port>
								<inst class_id_reference="31" object_id="_59">
									<type>0</type>
									<name>Loop_Loop2_proc_U0</name>
									<ssdmobj_id>21</ssdmobj_id>
								</inst>
							</item>
						</pins>
						<in_source_fork>0</in_source_fork>
						<in_sink_join>1</in_sink_join>
						<flag_in_gui>0</flag_in_gui>
					</item>
					<item class_id_reference="28" object_id="_60">
						<type>0</type>
						<name>Loop_Loop3_proc_U0</name>
						<ssdmobj_id>22</ssdmobj_id>
						<pins>
							<count>1</count>
							<item_version>0</item_version>
							<item class_id_reference="30" object_id="_61">
								<port class_id_reference="25" object_id="_62">
									<name>data_out2</name>
									<dir>1</dir>
									<type>2</type>
									<need_hs>1</need_hs>
									<top_port class_id_reference="25" object_id_reference="_48"></top_port>
									<chan class_id="-1"></chan>
								</port>
								<inst class_id_reference="31" object_id="_63">
									<type>0</type>
									<name>Loop_Loop3_proc_U0</name>
									<ssdmobj_id>22</ssdmobj_id>
								</inst>
							</item>
						</pins>
						<in_source_fork>0</in_source_fork>
						<in_sink_join>1</in_sink_join>
						<flag_in_gui>0</flag_in_gui>
					</item>
				</process_list>
				<channel_list class_id="32" tracking_level="0" version="0">
					<count>3</count>
					<item_version>0</item_version>
					<item class_id="26" tracking_level="1" version="0" object_id="_64">
						<type>1</type>
						<name>temp1</name>
						<ssdmobj_id>16</ssdmobj_id>
						<ctype>1</ctype>
						<depth>0</depth>
						<bitwidth>0</bitwidth>
						<suggested_type>0</suggested_type>
						<suggested_depth>2</suggested_depth>
						<source class_id_reference="30" object_id="_65">
							<port class_id_reference="25" object_id="_66">
								<name>in</name>
								<dir>0</dir>
								<type>3</type>
								<need_hs>0</need_hs>
								<top_port class_id="-1"></top_port>
								<chan class_id="-1"></chan>
							</port>
							<inst class_id_reference="31" object_id_reference="_52"></inst>
						</source>
						<sink class_id_reference="30" object_id="_67">
							<port class_id_reference="25" object_id="_68">
								<name>out</name>
								<dir>1</dir>
								<type>3</type>
								<need_hs>0</need_hs>
								<top_port class_id="-1"></top_port>
								<chan class_id="-1"></chan>
							</port>
							<inst class_id_reference="31" object_id="_69">
								<type>0</type>
								<name>split_U0</name>
								<ssdmobj_id>20</ssdmobj_id>
							</inst>
						</sink>
					</item>
					<item class_id_reference="26" object_id="_70">
						<type>1</type>
						<name>temp2</name>
						<ssdmobj_id>17</ssdmobj_id>
						<ctype>1</ctype>
						<depth>0</depth>
						<bitwidth>0</bitwidth>
						<suggested_type>0</suggested_type>
						<suggested_depth>2</suggested_depth>
						<source class_id_reference="30" object_id="_71">
							<port class_id_reference="25" object_id="_72">
								<name>in</name>
								<dir>0</dir>
								<type>3</type>
								<need_hs>0</need_hs>
								<top_port class_id="-1"></top_port>
								<chan class_id="-1"></chan>
							</port>
							<inst class_id_reference="31" object_id_reference="_69"></inst>
						</source>
						<sink class_id_reference="30" object_id="_73">
							<port class_id_reference="25" object_id="_74">
								<name>out</name>
								<dir>1</dir>
								<type>3</type>
								<need_hs>0</need_hs>
								<top_port class_id="-1"></top_port>
								<chan class_id="-1"></chan>
							</port>
							<inst class_id_reference="31" object_id_reference="_59"></inst>
						</sink>
					</item>
					<item class_id_reference="26" object_id="_75">
						<type>1</type>
						<name>temp3</name>
						<ssdmobj_id>18</ssdmobj_id>
						<ctype>1</ctype>
						<depth>0</depth>
						<bitwidth>0</bitwidth>
						<suggested_type>0</suggested_type>
						<suggested_depth>2</suggested_depth>
						<source class_id_reference="30" object_id="_76">
							<port class_id_reference="25" object_id="_77">
								<name>in</name>
								<dir>0</dir>
								<type>3</type>
								<need_hs>0</need_hs>
								<top_port class_id="-1"></top_port>
								<chan class_id="-1"></chan>
							</port>
							<inst class_id_reference="31" object_id_reference="_69"></inst>
						</source>
						<sink class_id_reference="30" object_id="_78">
							<port class_id_reference="25" object_id="_79">
								<name>out</name>
								<dir>1</dir>
								<type>3</type>
								<need_hs>0</need_hs>
								<top_port class_id="-1"></top_port>
								<chan class_id="-1"></chan>
							</port>
							<inst class_id_reference="31" object_id_reference="_63"></inst>
						</sink>
					</item>
				</channel_list>
				<net_list class_id="33" tracking_level="0" version="0">
					<count>0</count>
					<item_version>0</item_version>
				</net_list>
			</mDfPipe>
		</item>
	</cdfg_regions>
	<fsm class_id="34" tracking_level="1" version="0" object_id="_80">
		<states class_id="35" tracking_level="0" version="0">
			<count>6</count>
			<item_version>0</item_version>
			<item class_id="36" tracking_level="1" version="0" object_id="_81">
				<id>1</id>
				<operations class_id="37" tracking_level="0" version="0">
					<count>5</count>
					<item_version>0</item_version>
					<item class_id="38" tracking_level="1" version="0" object_id="_82">
						<id>15</id>
						<stage>1</stage>
						<latency>1</latency>
					</item>
					<item class_id_reference="38" object_id="_83">
						<id>16</id>
						<stage>1</stage>
						<latency>1</latency>
					</item>
					<item class_id_reference="38" object_id="_84">
						<id>17</id>
						<stage>1</stage>
						<latency>1</latency>
					</item>
					<item class_id_reference="38" object_id="_85">
						<id>18</id>
						<stage>1</stage>
						<latency>1</latency>
					</item>
					<item class_id_reference="38" object_id="_86">
						<id>19</id>
						<stage>2</stage>
						<latency>2</latency>
					</item>
				</operations>
			</item>
			<item class_id_reference="36" object_id="_87">
				<id>2</id>
				<operations>
					<count>1</count>
					<item_version>0</item_version>
					<item class_id_reference="38" object_id="_88">
						<id>19</id>
						<stage>1</stage>
						<latency>2</latency>
					</item>
				</operations>
			</item>
			<item class_id_reference="36" object_id="_89">
				<id>3</id>
				<operations>
					<count>1</count>
					<item_version>0</item_version>
					<item class_id_reference="38" object_id="_90">
						<id>20</id>
						<stage>2</stage>
						<latency>2</latency>
					</item>
				</operations>
			</item>
			<item class_id_reference="36" object_id="_91">
				<id>4</id>
				<operations>
					<count>1</count>
					<item_version>0</item_version>
					<item class_id_reference="38" object_id="_92">
						<id>20</id>
						<stage>1</stage>
						<latency>2</latency>
					</item>
				</operations>
			</item>
			<item class_id_reference="36" object_id="_93">
				<id>5</id>
				<operations>
					<count>2</count>
					<item_version>0</item_version>
					<item class_id_reference="38" object_id="_94">
						<id>21</id>
						<stage>2</stage>
						<latency>2</latency>
					</item>
					<item class_id_reference="38" object_id="_95">
						<id>22</id>
						<stage>2</stage>
						<latency>2</latency>
					</item>
				</operations>
			</item>
			<item class_id_reference="36" object_id="_96">
				<id>6</id>
				<operations>
					<count>13</count>
					<item_version>0</item_version>
					<item class_id_reference="38" object_id="_97">
						<id>5</id>
						<stage>1</stage>
						<latency>1</latency>
					</item>
					<item class_id_reference="38" object_id="_98">
						<id>6</id>
						<stage>1</stage>
						<latency>1</latency>
					</item>
					<item class_id_reference="38" object_id="_99">
						<id>7</id>
						<stage>1</stage>
						<latency>1</latency>
					</item>
					<item class_id_reference="38" object_id="_100">
						<id>8</id>
						<stage>1</stage>
						<latency>1</latency>
					</item>
					<item class_id_reference="38" object_id="_101">
						<id>9</id>
						<stage>1</stage>
						<latency>1</latency>
					</item>
					<item class_id_reference="38" object_id="_102">
						<id>10</id>
						<stage>1</stage>
						<latency>1</latency>
					</item>
					<item class_id_reference="38" object_id="_103">
						<id>11</id>
						<stage>1</stage>
						<latency>1</latency>
					</item>
					<item class_id_reference="38" object_id="_104">
						<id>12</id>
						<stage>1</stage>
						<latency>1</latency>
					</item>
					<item class_id_reference="38" object_id="_105">
						<id>13</id>
						<stage>1</stage>
						<latency>1</latency>
					</item>
					<item class_id_reference="38" object_id="_106">
						<id>14</id>
						<stage>1</stage>
						<latency>1</latency>
					</item>
					<item class_id_reference="38" object_id="_107">
						<id>21</id>
						<stage>1</stage>
						<latency>2</latency>
					</item>
					<item class_id_reference="38" object_id="_108">
						<id>22</id>
						<stage>1</stage>
						<latency>2</latency>
					</item>
					<item class_id_reference="38" object_id="_109">
						<id>23</id>
						<stage>1</stage>
						<latency>1</latency>
					</item>
				</operations>
			</item>
		</states>
		<transitions class_id="39" tracking_level="0" version="0">
			<count>5</count>
			<item_version>0</item_version>
			<item class_id="40" tracking_level="1" version="0" object_id="_110">
				<inState>1</inState>
				<outState>2</outState>
				<condition class_id="41" tracking_level="0" version="0">
					<id>-1</id>
					<sop class_id="42" tracking_level="0" version="0">
						<count>1</count>
						<item_version>0</item_version>
						<item class_id="43" tracking_level="0" version="0">
							<count>0</count>
							<item_version>0</item_version>
						</item>
					</sop>
				</condition>
			</item>
			<item class_id_reference="40" object_id="_111">
				<inState>2</inState>
				<outState>3</outState>
				<condition>
					<id>-1</id>
					<sop>
						<count>1</count>
						<item_version>0</item_version>
						<item>
							<count>0</count>
							<item_version>0</item_version>
						</item>
					</sop>
				</condition>
			</item>
			<item class_id_reference="40" object_id="_112">
				<inState>3</inState>
				<outState>4</outState>
				<condition>
					<id>-1</id>
					<sop>
						<count>1</count>
						<item_version>0</item_version>
						<item>
							<count>0</count>
							<item_version>0</item_version>
						</item>
					</sop>
				</condition>
			</item>
			<item class_id_reference="40" object_id="_113">
				<inState>4</inState>
				<outState>5</outState>
				<condition>
					<id>-1</id>
					<sop>
						<count>1</count>
						<item_version>0</item_version>
						<item>
							<count>0</count>
							<item_version>0</item_version>
						</item>
					</sop>
				</condition>
			</item>
			<item class_id_reference="40" object_id="_114">
				<inState>5</inState>
				<outState>6</outState>
				<condition>
					<id>-1</id>
					<sop>
						<count>1</count>
						<item_version>0</item_version>
						<item>
							<count>0</count>
							<item_version>0</item_version>
						</item>
					</sop>
				</condition>
			</item>
		</transitions>
	</fsm>
	<res class_id="-1"></res>
	<node_label_latency class_id="45" tracking_level="0" version="0">
		<count>9</count>
		<item_version>0</item_version>
		<item class_id="46" tracking_level="0" version="0">
			<first>15</first>
			<second class_id="47" tracking_level="0" version="0">
				<first>0</first>
				<second>0</second>
			</second>
		</item>
		<item>
			<first>16</first>
			<second>
				<first>0</first>
				<second>0</second>
			</second>
		</item>
		<item>
			<first>17</first>
			<second>
				<first>0</first>
				<second>0</second>
			</second>
		</item>
		<item>
			<first>18</first>
			<second>
				<first>0</first>
				<second>0</second>
			</second>
		</item>
		<item>
			<first>19</first>
			<second>
				<first>0</first>
				<second>1</second>
			</second>
		</item>
		<item>
			<first>20</first>
			<second>
				<first>2</first>
				<second>1</second>
			</second>
		</item>
		<item>
			<first>21</first>
			<second>
				<first>4</first>
				<second>1</second>
			</second>
		</item>
		<item>
			<first>22</first>
			<second>
				<first>4</first>
				<second>1</second>
			</second>
		</item>
		<item>
			<first>23</first>
			<second>
				<first>5</first>
				<second>0</second>
			</second>
		</item>
	</node_label_latency>
	<bblk_ent_exit class_id="48" tracking_level="0" version="0">
		<count>1</count>
		<item_version>0</item_version>
		<item class_id="49" tracking_level="0" version="0">
			<first>24</first>
			<second class_id="50" tracking_level="0" version="0">
				<first>0</first>
				<second>5</second>
			</second>
		</item>
	</bblk_ent_exit>
	<regions class_id="51" tracking_level="0" version="0">
		<count>1</count>
		<item_version>0</item_version>
		<item class_id="52" tracking_level="1" version="0" object_id="_115">
			<region_name>foo_m</region_name>
			<basic_blocks>
				<count>1</count>
				<item_version>0</item_version>
				<item>24</item>
			</basic_blocks>
			<nodes>
				<count>19</count>
				<item_version>0</item_version>
				<item>5</item>
				<item>6</item>
				<item>7</item>
				<item>8</item>
				<item>9</item>
				<item>10</item>
				<item>11</item>
				<item>12</item>
				<item>13</item>
				<item>14</item>
				<item>15</item>
				<item>16</item>
				<item>17</item>
				<item>18</item>
				<item>19</item>
				<item>20</item>
				<item>21</item>
				<item>22</item>
				<item>23</item>
			</nodes>
			<anchor_node>-1</anchor_node>
			<region_type>16</region_type>
			<interval>0</interval>
			<pipe_depth>0</pipe_depth>
			<mDBIIViolationVec class_id="53" tracking_level="0" version="0">
				<count>0</count>
				<item_version>0</item_version>
			</mDBIIViolationVec>
		</item>
	</regions>
	<dp_fu_nodes class_id="54" tracking_level="0" version="0">
		<count>8</count>
		<item_version>0</item_version>
		<item class_id="55" tracking_level="0" version="0">
			<first>40</first>
			<second>
				<count>1</count>
				<item_version>0</item_version>
				<item>16</item>
			</second>
		</item>
		<item>
			<first>44</first>
			<second>
				<count>1</count>
				<item_version>0</item_version>
				<item>17</item>
			</second>
		</item>
		<item>
			<first>48</first>
			<second>
				<count>1</count>
				<item_version>0</item_version>
				<item>18</item>
			</second>
		</item>
		<item>
			<first>52</first>
			<second>
				<count>1</count>
				<item_version>0</item_version>
				<item>15</item>
			</second>
		</item>
		<item>
			<first>58</first>
			<second>
				<count>2</count>
				<item_version>0</item_version>
				<item>19</item>
				<item>19</item>
			</second>
		</item>
		<item>
			<first>68</first>
			<second>
				<count>2</count>
				<item_version>0</item_version>
				<item>20</item>
				<item>20</item>
			</second>
		</item>
		<item>
			<first>75</first>
			<second>
				<count>2</count>
				<item_version>0</item_version>
				<item>21</item>
				<item>21</item>
			</second>
		</item>
		<item>
			<first>82</first>
			<second>
				<count>2</count>
				<item_version>0</item_version>
				<item>22</item>
				<item>22</item>
			</second>
		</item>
	</dp_fu_nodes>
	<dp_fu_nodes_expression class_id="57" tracking_level="0" version="0">
		<count>3</count>
		<item_version>0</item_version>
		<item class_id="58" tracking_level="0" version="0">
			<first>temp1_alloca_fu_40</first>
			<second>
				<count>1</count>
				<item_version>0</item_version>
				<item>16</item>
			</second>
		</item>
		<item>
			<first>temp2_alloca_fu_44</first>
			<second>
				<count>1</count>
				<item_version>0</item_version>
				<item>17</item>
			</second>
		</item>
		<item>
			<first>temp3_alloca_fu_48</first>
			<second>
				<count>1</count>
				<item_version>0</item_version>
				<item>18</item>
			</second>
		</item>
	</dp_fu_nodes_expression>
	<dp_fu_nodes_module>
		<count>4</count>
		<item_version>0</item_version>
		<item>
			<first>grp_Loop_Loop1_proc_fu_58</first>
			<second>
				<count>2</count>
				<item_version>0</item_version>
				<item>19</item>
				<item>19</item>
			</second>
		</item>
		<item>
			<first>grp_Loop_Loop2_proc_fu_75</first>
			<second>
				<count>2</count>
				<item_version>0</item_version>
				<item>21</item>
				<item>21</item>
			</second>
		</item>
		<item>
			<first>grp_Loop_Loop3_proc_fu_82</first>
			<second>
				<count>2</count>
				<item_version>0</item_version>
				<item>22</item>
				<item>22</item>
			</second>
		</item>
		<item>
			<first>grp_split_fu_68</first>
			<second>
				<count>2</count>
				<item_version>0</item_version>
				<item>20</item>
				<item>20</item>
			</second>
		</item>
	</dp_fu_nodes_module>
	<dp_fu_nodes_io>
		<count>1</count>
		<item_version>0</item_version>
		<item>
			<first>scale_read_read_fu_52</first>
			<second>
				<count>1</count>
				<item_version>0</item_version>
				<item>15</item>
			</second>
		</item>
	</dp_fu_nodes_io>
	<return_ports>
		<count>0</count>
		<item_version>0</item_version>
	</return_ports>
	<dp_mem_port_nodes class_id="59" tracking_level="0" version="0">
		<count>0</count>
		<item_version>0</item_version>
	</dp_mem_port_nodes>
	<dp_reg_nodes>
		<count>1</count>
		<item_version>0</item_version>
		<item>
			<first>89</first>
			<second>
				<count>1</count>
				<item_version>0</item_version>
				<item>15</item>
			</second>
		</item>
	</dp_reg_nodes>
	<dp_regname_nodes>
		<count>1</count>
		<item_version>0</item_version>
		<item>
			<first>scale_read_reg_89</first>
			<second>
				<count>1</count>
				<item_version>0</item_version>
				<item>15</item>
			</second>
		</item>
	</dp_regname_nodes>
	<dp_reg_phi>
		<count>0</count>
		<item_version>0</item_version>
	</dp_reg_phi>
	<dp_regname_phi>
		<count>0</count>
		<item_version>0</item_version>
	</dp_regname_phi>
	<dp_port_io_nodes class_id="60" tracking_level="0" version="0">
		<count>1</count>
		<item_version>0</item_version>
		<item class_id="61" tracking_level="0" version="0">
			<first>scale</first>
			<second>
				<count>1</count>
				<item_version>0</item_version>
				<item>
					<first>read</first>
					<second>
						<count>1</count>
						<item_version>0</item_version>
						<item>15</item>
					</second>
				</item>
			</second>
		</item>
	</dp_port_io_nodes>
	<port2core>
		<count>3</count>
		<item_version>0</item_version>
		<item>
			<first>1</first>
			<second>
				<first>27</first>
				<second>136</second>
			</second>
		</item>
		<item>
			<first>3</first>
			<second>
				<first>27</first>
				<second>136</second>
			</second>
		</item>
		<item>
			<first>4</first>
			<second>
				<first>27</first>
				<second>136</second>
			</second>
		</item>
	</port2core>
	<node2core>
		<count>7</count>
		<item_version>0</item_version>
		<item>
			<first>16</first>
			<second>
				<first>27</first>
				<second>136</second>
			</second>
		</item>
		<item>
			<first>17</first>
			<second>
				<first>27</first>
				<second>136</second>
			</second>
		</item>
		<item>
			<first>18</first>
			<second>
				<first>27</first>
				<second>136</second>
			</second>
		</item>
		<item>
			<first>19</first>
			<second>
				<first>-1</first>
				<second>-1</second>
			</second>
		</item>
		<item>
			<first>20</first>
			<second>
				<first>-1</first>
				<second>-1</second>
			</second>
		</item>
		<item>
			<first>21</first>
			<second>
				<first>-1</first>
				<second>-1</second>
			</second>
		</item>
		<item>
			<first>22</first>
			<second>
				<first>-1</first>
				<second>-1</second>
			</second>
		</item>
	</node2core>
</syndb>
</boost_serialization>

