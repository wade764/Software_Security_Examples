##
# This module requires Metasploit: http://metasploit.com/download
# Current source: https://github.com/rapid7/metasploit-framework
##

require 'msf/core'

class MetasploitModule < Msf::Exploit::Remote
  Rank = NormalRanking
		include 
		
  def initialize(info={})
    super(update_info(info,
      'Name'           => "",
      'Description'    => %q{
        
      },
      'License'        => MSF_LICENSE,
      'Author'         => [ 'Name' ],
      'References'     =>
        [
          [ '', '' ]
        ],
      'Platform'       => '',
      'Targets'        =>
        [
          [ '',
            {
              'Ret' =>  # This will be available in `target.ret`
            }
          ]
        ],
      'Payload'        =>
        {
          'BadChars' => "\x00"
        },
      'Privileged'     => false,
      'DisclosureDate' => "",
      'DefaultTarget'  => 0))
      
      register_options(
      [
		
      ], self.class)
  end

  def check
    # For the check command
  end

  def exploit
    # Main function

  end

end
